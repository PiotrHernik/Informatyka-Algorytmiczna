package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
	"sync/atomic"
)

const (
	NrOfProcesses = 2
	MinSteps      = 50
	MaxSteps      = 100
	MinDelay      = 10 * time.Millisecond
	MaxDelay      = 50 * time.Millisecond
)

type ProcessState int

const (
	LocalSection ProcessState = iota
	EntryProtocol
	CriticalSection
	ExitProtocol
)

var (
	BoardWidth  = NrOfProcesses
	BoardHeight = int(ExitProtocol) + 1
	StartTime   = time.Now()
	C1 int32 = 0
	C2 int32 = 0
	Last int32 = 1
)

type Position struct {
	X int // 0..BoardWidth-1
	Y int // 0..BoardHeight-1
}

type Trace struct {
	TimeStamp time.Duration
	ID        int
	Position  Position
	Symbol    rune
}

type Process struct {
	ID       int
	Symbol   rune
	Position Position
}

type ProcessTask struct {
	process     Process
	rand        *rand.Rand
	nrOfSteps   int
	traces      []Trace
	tracesMutex sync.Mutex
}

func (pt *ProcessTask) init(id int, seed int64, symbol rune) {
	pt.rand = rand.New(rand.NewSource(seed))
	pt.process.ID = id
	pt.process.Symbol = symbol
	pt.process.Position = Position{
		X: id,
		Y: int(LocalSection),
	}
	pt.nrOfSteps = MinSteps + pt.rand.Intn(MaxSteps-MinSteps+1)

	// Store initial trace
	pt.storeTrace()
}

func (pt *ProcessTask) storeTrace() {
	pt.tracesMutex.Lock()
	defer pt.tracesMutex.Unlock()

	pt.traces = append(pt.traces, Trace{
		TimeStamp: time.Since(StartTime),
		ID:        pt.process.ID,
		Position:  pt.process.Position,
		Symbol:    pt.process.Symbol,
	})
}

func (pt *ProcessTask) changeState(state ProcessState) {
	pt.process.Position.Y = int(state)
	pt.storeTrace()
}

func (pt *ProcessTask) run(wg *sync.WaitGroup, printerChan chan []Trace) {
	defer wg.Done()

	// Wait a random time before starting (simulate Ada's accept Start)
	time.Sleep(time.Duration(pt.rand.Int63n(int64(10 * time.Millisecond))))

	for step := 0; step < pt.nrOfSteps/4; step++ { // Divided by 4 for testing as in Ada code
		// Local section
		delay := MinDelay + time.Duration(float64(pt.rand.Float64())*float64(MaxDelay-MinDelay))
		time.Sleep(delay)

		// Entry protocol
		pt.changeState(EntryProtocol)

		if pt.process.ID == 0 {
			atomic.StoreInt32(&C1, 1)
			atomic.StoreInt32(&Last, 1)
			for atomic.LoadInt32(&C2) != 0 && atomic.LoadInt32(&Last) == 1 {
				time.Sleep(10 * time.Microsecond)
			}
		} else {
			atomic.StoreInt32(&C2, 1)
			atomic.StoreInt32(&Last, 2)
			for atomic.LoadInt32(&C1) != 0 && atomic.LoadInt32(&Last) == 2 {
				time.Sleep(10 * time.Microsecond)
			}
		}

		// Critical section
		pt.changeState(CriticalSection)
		delay = MinDelay + time.Duration(float64(pt.rand.Float64())*float64(MaxDelay-MinDelay))
		time.Sleep(delay)

		// Exit protocol
		pt.changeState(ExitProtocol)
		if pt.process.ID == 0 {
			atomic.StoreInt32(&C1, 0)
		} else {
			atomic.StoreInt32(&C2, 0)
		}
		// Implement exit protocol here...

		// Back to local section
		pt.changeState(LocalSection)
	}

	// Send traces to printer
	printerChan <- pt.traces
}

// Add this String method to the ProcessState type
func (ps ProcessState) String() string {
	names := []string{
		"LOCAL_SECTION",
		"ENTRY_PROTOCOL",
		"CRITICAL_SECTION",
		"EXIT_PROTOCOL",
	}
	if int(ps) < len(names) {
		return names[ps]
	}
	return "UNKNOWN_STATE"
}

func printer(printerChan chan []Trace, done chan bool) {
	// Collect and print traces
	for i := 0; i < NrOfProcesses; i++ {
		traces := <-printerChan
		for _, trace := range traces {
			fmt.Printf("%.10f %d %d %d %c\n",
				trace.TimeStamp.Seconds(),
				trace.ID,
				trace.Position.X,
				trace.Position.Y,
				trace.Symbol)
		}
	}

	

	// Then modify the printer section to:
	fmt.Printf("-1 %d %d %d ", NrOfProcesses, BoardWidth, BoardHeight)
	for state := LocalSection; state <= ExitProtocol; state++ {
		fmt.Printf("%s;", state.String())
	}
	fmt.Println("EXTRA_LABEL;")

	done <- true
}

func makeSeeds(n int) []int64 {
	seeds := make([]int64, n)
	for i := 0; i < n; i++ {
		seeds[i] = time.Now().UnixNano() + int64(i*1000)
	}
	return seeds
}


func main() {
	seeds := makeSeeds(NrOfProcesses)
	printerChan := make(chan []Trace, NrOfProcesses)
	done := make(chan bool)

	// Start printer
	go printer(printerChan, done)

	var wg sync.WaitGroup
	processTasks := make([]*ProcessTask, NrOfProcesses)

	// Initialize and start processes
	symbol := 'A'
	for i := 0; i < NrOfProcesses; i++ {
		pt := &ProcessTask{}
		pt.init(i, seeds[i], symbol)
		processTasks[i] = pt
		symbol++

		wg.Add(1)
		go pt.run(&wg, printerChan)
	}

	// Wait for all processes to finish
	wg.Wait()

	// Wait for printer to finish
	<-done
}