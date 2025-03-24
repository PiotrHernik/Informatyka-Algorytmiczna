package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

const (
	NrOfTravelers = 15
	MinSteps      = 10
	MaxSteps      = 100
	MinDelay      = 10 * time.Millisecond
	MaxDelay      = 50 * time.Millisecond
	BoardWidth    = 15
	BoardHeight   = 15
)

type Field struct {
	mu sync.Mutex
}

var Fields [BoardWidth][BoardHeight] Field


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
		startPos := PositionType{
			X: id,
			Y: id,
		}
		
		if Enter(&startPos, traveler.ID) { 
			traveler.Position = startPos
			break
		}
	}
	
	var Direction int

	if id % 2 == 0 {
		Direction = rng.Intn(2)
		} else {
			Direction = 2 + rng.Intn(2)
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

		switch Direction {
		case 0:
			MoveUp(&newPos)
		case 1:
			MoveDown(&newPos)
		case 2:
			MoveLeft(&newPos)
		case 3:
			MoveRight(&newPos)
		}

		if EnterWithTimeout(&newPos, traveler.ID, 5*MaxDelay) {
			Leave(&traveler.Position, traveler.ID) // Opuszczamy stare pole
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

		if shouldBreak {
			break
		}
	}
	Leave(&traveler.Position, traveler.ID)
	reports <- traces
}

func Enter(pos *PositionType, travelerID int) bool {
	return Fields[pos.X][pos.Y].mu.TryLock()
}

func EnterWithTimeout(pos *PositionType, travelerID int, timeout time.Duration) bool {
	timer := time.NewTimer(timeout)
	defer timer.Stop()

	locked := make(chan bool, 1)

	go func() {
        Fields[pos.X][pos.Y].mu.Lock()

        locked <- true
    }()

	select {
	case <-timer.C:
		fmt.Printf("Traveler %d timeout at (%d, %d)\n", travelerID, pos.X, pos.Y)
		return false
	case <-locked:

		return true
	}
	return false
}

func Leave(pos *PositionType, travelerID int) {
	Fields[pos.X][pos.Y].mu.Unlock()
}

var StartTime time.Time

var startChan = make(chan struct{})

func main() {
    StartTime = time.Now()
    seeds := MakeSeeds(NrOfTravelers)
    reports := make(chan TracesSequenceType, NrOfTravelers)
    var wgPrinter sync.WaitGroup
    var wgInit sync.WaitGroup
    var wgMove sync.WaitGroup

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
