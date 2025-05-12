package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

// Stałe
const (
	NrOfTravelers = 3
	MinSteps      = 10
	MaxSteps      = 100
	MinDelay      = 10 * time.Millisecond
	MaxDelay      = 50 * time.Millisecond
	BoardWidth    = 2
	BoardHeight   = 2
)


// type Field struct {
// 	mu sync.Mutex
// }

type Field struct {
    moveChan chan TryMoveRequest
    leaveChan chan LeaveRequest
    quit chan bool
}

type TryMoveRequest struct {
	ID      int
	Resp    chan int
}

type LeaveRequest struct {
	ID      int
	Resp    chan int
}

var Fields [BoardWidth][BoardHeight] Field

func goField(moveChan chan TryMoveRequest, leaveChan chan LeaveRequest, quit chan bool) {
	var (
		isOccupied bool
		travelerID = -2
		// mutex sync.Mutex
	)

	for {
		select {
		case req := <-moveChan:
			// mutex.Lock()
			if !isOccupied {
				isOccupied = true
				travelerID = req.ID
				// mutex.Unlock()
				req.Resp <- 1
			} else {
				// mutex.Unlock()
				req.Resp <- -1
			}

		case req := <-leaveChan:
			// mutex.Lock()
			if isOccupied && travelerID == req.ID {
				isOccupied = false
				travelerID = -2
				// mutex.Unlock()
				req.Resp <- 1
			} else {
				// mutex.Unlock()
				req.Resp <- -1
			}

		case <-quit:
			return
		}
	}
}

type PositionType struct {
	X int
	Y int
}

type TraceType struct {
	TimeStamp time.Duration
	ID        int
	Position  PositionType
	Symbol    rune
}

type TracesSequenceType struct {
	Last       int
	TraceArray [MaxSteps]TraceType
}

type TravelerType struct {
	ID       int
	Symbol   rune
	Position PositionType
}

func MoveDown(position *PositionType) {
	position.Y = (position.Y + 1) % BoardHeight
}

func MoveUp(position *PositionType) {
	position.Y = (position.Y + BoardHeight - 1) % BoardHeight
}

func MoveRight(position *PositionType) {
	position.X = (position.X + 1) % BoardWidth
}

func MoveLeft(position *PositionType) {
	position.X = (position.X + BoardWidth - 1) % BoardWidth
}

func MakeSeeds(nrOfTravelers int) []int64 {
	seeds := make([]int64, nrOfTravelers)
	for i := 0; i < nrOfTravelers; i++ {
		seeds[i] = time.Now().UnixNano() + int64(i)
	}
	return seeds
}

func PrintTrace(trace TraceType) {
	seconds := trace.TimeStamp.Seconds()
	fmt.Printf("%.6f %d %d %d %c\n", seconds, trace.ID, trace.Position.X, trace.Position.Y, trace.Symbol)
}

func PrintTraces(traces TracesSequenceType) {
	for i := 0; i <= traces.Last; i++ {
		PrintTrace(traces.TraceArray[i])
	}
}

func Printer(reports chan TracesSequenceType, wgPrinter *sync.WaitGroup) {
    defer wgPrinter.Done()
    for traces := range reports {
        PrintTraces(traces)
    }
}

func tryEnterField(pos PositionType, travelerID int, timeout time.Duration) bool {
    resp := make(chan int)
    req := TryMoveRequest{ID: travelerID, Resp: resp}
	timer := time.NewTimer(timeout)
	defer timer.Stop()
    
    for {
		select {
		case Fields[pos.X][pos.Y].moveChan <- req:
			select {
			case result := <-resp:
				return result == 1
			case <-timer.C:
				fmt.Printf("Traveler %d: Timeout waiting for field response at %v\n", travelerID, pos)
				return false
			}
		case <-timer.C:
			fmt.Printf("Traveler %d: Timeout trying to send request to field at %v\n", travelerID, pos)
			return false
		default:
			time.Sleep(50 * time.Millisecond)
		}
	}
}

func TravelerTask(id int, seed int64, symbol rune, reports chan TracesSequenceType, wgMove *sync.WaitGroup, wgInit *sync.WaitGroup) {
	defer wgMove.Done()

	rng := rand.New(rand.NewSource(seed))

	traveler := TravelerType{
		ID:     id,
		Symbol: symbol,
		Position: PositionType{
			X: rng.Intn(BoardWidth),
			Y: rng.Intn(BoardHeight),
		},
	}

	for {
		fmt.Println("Inicjalizacja in for dla travelera: %d", id)
		startPos := PositionType{
			X: rng.Intn(BoardWidth),
			Y: rng.Intn(BoardHeight),
		}
		fmt.Println("Traveler: %d, próbuje wejść na pole: %d, %d", id, startPos.X, startPos.Y)
		if tryEnterField(startPos, traveler.ID, 5*MaxDelay) {

			fmt.Printf("traveler %d llocked Fileld: %d, %d locked\n", traveler.ID, startPos.X, startPos.Y)
			traveler.Position = startPos
			break
		} else {
			fmt.Println("Nie udało się travelerowi: %d wejsć na pole: %d, %d", id, startPos.X, startPos.Y)
		}
	}

	wgInit.Done()

	<-startChan

	nrOfSteps := MinSteps + rng.Intn(MaxSteps-MinSteps)

	var traces TracesSequenceType
	traces.Last = 0
	traces.TraceArray[0] = TraceType{
		TimeStamp: time.Since(StartTime),
		ID:        traveler.ID,
		Position:  traveler.Position,
		Symbol:    traveler.Symbol,
	}


	var shouldBreak bool = false

	for step := 0; step < nrOfSteps; step++ {
		delay := MinDelay + time.Duration(float64(MaxDelay-MinDelay)*rng.Float64())
		time.Sleep(delay)

		newPos := traveler.Position

		switch rng.Intn(4) {
		case 0:
			MoveUp(&newPos)
		case 1:
			MoveDown(&newPos)
		case 2:
			MoveLeft(&newPos)
		case 3:
			MoveRight(&newPos)
		}

		if tryEnterField(newPos, traveler.ID, 5*MaxDelay) {
			resp := make(chan int)
			leaveReq := LeaveRequest{ID: traveler.ID, Resp: resp}
			Fields[traveler.Position.X][traveler.Position.Y].leaveChan <- leaveReq
			select {
			case result := <-resp:
				if result == 1 {
					fmt.Println("Traveler", traveler.ID, "left a field it's ok")
				} else {
					fmt.Println("Traveler", traveler.ID, " didn't leave a field")
				}
			case <-time.After(time.Second):
				fmt.Println("Dupa jasia")
			// default:
			// 	fmt.Println("Traveler can't leave a field")
			}
			// Leave(&traveler.Position, traveler.ID) 
			traveler.Position = newPos
		} else {
			traveler.Symbol = rune(traveler.Symbol + 32)
			shouldBreak = true
		}


		traces.Last++
		traces.TraceArray[traces.Last] = TraceType{
			TimeStamp: time.Since(StartTime),
			ID:        traveler.ID,
			Position:  traveler.Position,
			Symbol:    traveler.Symbol,
		}

		if (shouldBreak){
			break
		}
	}
	// Leave(&traveler.Position, traveler.ID)
	resp := make(chan int)
	leaveReq := LeaveRequest{ID: traveler.ID, Resp: resp}
	Fields[traveler.Position.X][traveler.Position.Y].leaveChan <- leaveReq
	reports <- traces

}

// func Enter(pos *PositionType, travelerID int) bool {
// 	return Fields[pos.X][pos.Y].mu.TryLock()
// }

// func EnterWithTimeout(pos *PositionType, travelerID int, timeout time.Duration) bool {
// 	timer := time.NewTimer(timeout)
// 	defer timer.Stop()

// 	locked := make(chan bool, 1)

// 	go func() {
//         Fields[pos.X][pos.Y].mu.Lock()
// 		// fmt.Printf("traveler %d llocked Fileld: %d, %d locked\n", travelerID, pos.X, pos.Y)

//         locked <- true
//     }()

// 	select {
// 	case <-timer.C:
// 		// fmt.Printf("Traveler %d timeout at (%d, %d)\n", travelerID, pos.X, pos.Y)
// 		return false
// 	case <-locked:

// 		return true
// 	}
// 	return false
// }

// func Leave(pos *PositionType, travelerID int) {
// 	// fmt.Printf("traveler %d UNLOCK Fileld: %d, %d locked\n", travelerID, pos.X, pos.Y)

// 	Fields[pos.X][pos.Y].mu.Unlock()
// }

var StartTime time.Time

var startChan = make(chan struct{})

func main() {
    StartTime = time.Now()
    seeds := MakeSeeds(NrOfTravelers)
    reports := make(chan TracesSequenceType, NrOfTravelers)
    var wgPrinter sync.WaitGroup
    var wgInit sync.WaitGroup
    var wgMove sync.WaitGroup

	for x := 0; x < BoardWidth; x++ {
		for y := 0; y < BoardHeight; y++ {
			Fields[x][y] = Field{
				moveChan: make(chan TryMoveRequest),
				leaveChan: make(chan LeaveRequest),
				quit: make(chan bool),
			}
			go goField(Fields[x][y].moveChan, Fields[x][y].leaveChan, Fields[x][y].quit)
		}
	}

    fmt.Printf("-1 %d %d %d\n", NrOfTravelers, BoardWidth, BoardHeight)

    wgPrinter.Add(1)
    go Printer(reports, &wgPrinter)

	wgInit.Add(NrOfTravelers)
    wgMove.Add(NrOfTravelers)

    symbol := 'A'
    for i := 0; i < NrOfTravelers; i++ {
        go TravelerTask(i, seeds[i], symbol, reports, &wgMove, &wgInit)
        symbol++
    }

	wgInit.Wait()
	close(startChan)

	wgMove.Wait()
		
	close(reports)
	wgPrinter.Wait()
}
