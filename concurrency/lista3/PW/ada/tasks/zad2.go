package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

// Stałe
const (
	NrOfTravelers = 15
	MinSteps      = 10
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

type TraceType struct {
	TimeStamp time.Duration
	ID        int
	Position  PositionType
	Symbol    rune
}

// TracesSequenceType reprezentuje sekwencję śladów
type TracesSequenceType struct {
	Last       int
	TraceArray [MaxSteps]TraceType
}

// TravelerType reprezentuje podróżnego
type TravelerType struct {
	ID       int
	Symbol   rune
	Position PositionType
}

// Funkcje do poruszania się po planszy

// MoveDown przesuwa pozycję w dół
func MoveDown(position *PositionType) {
	position.Y = (position.Y + 1) % BoardHeight
}

// MoveUp przesuwa pozycję w górę
func MoveUp(position *PositionType) {
	position.Y = (position.Y + BoardHeight - 1) % BoardHeight
}

// MoveRight przesuwa pozycję w prawo
func MoveRight(position *PositionType) {
	position.X = (position.X + 1) % BoardWidth
}

// MoveLeft przesuwa pozycję w lewo
func MoveLeft(position *PositionType) {
	position.X = (position.X + BoardWidth - 1) % BoardWidth
}

// MakeSeeds generuje ziarna dla generatorów liczb losowych
func MakeSeeds(nrOfTravelers int) []int64 {
	seeds := make([]int64, nrOfTravelers)
	for i := 0; i < nrOfTravelers; i++ {
		seeds[i] = time.Now().UnixNano() + int64(i) // Używamy czasu jako ziarna
	}
	return seeds
}

// PrintTrace wyświetla ślad podróżnego w formacie identycznym jak w Adzie
func PrintTrace(trace TraceType) {
	// Konwersja Duration na sekundy
	seconds := trace.TimeStamp.Seconds()
	fmt.Printf("%.6f %d %d %d %c\n", seconds, trace.ID, trace.Position.X, trace.Position.Y, trace.Symbol)
}

// PrintTraces wyświetla wszystkie ślady
func PrintTraces(traces TracesSequenceType) {
	for i := 0; i <= traces.Last; i++ {
		PrintTrace(traces.TraceArray[i])
	}
}

// Printer zbiera i wyświetla raporty śladów
func Printer(reports chan TracesSequenceType, wg *sync.WaitGroup) {
	defer wg.Done()
	for i := 0; i < NrOfTravelers; i++ {
		traces := <-reports
		PrintTraces(traces)
	}
}

// TravelerTask symuluje podróżnego
func TravelerTask(id int, seed int64, symbol rune, reports chan TracesSequenceType, wg *sync.WaitGroup) {
	defer wg.Done()

	// Inicjalizacja generatora liczb losowych
	rng := rand.New(rand.NewSource(seed))

	// Inicjalizacja podróżnego
	traveler := TravelerType{
		ID:     id,
		Symbol: symbol,
		Position: PositionType{
			X: rng.Intn(BoardWidth),
			Y: rng.Intn(BoardHeight),
		},
	}

	// Liczba kroków do wykonania
	nrOfSteps := MinSteps + rng.Intn(MaxSteps-MinSteps)

	// Sekwencja śladów
	var traces TracesSequenceType
	traces.Last = 0
	traces.TraceArray[0] = TraceType{
		TimeStamp: time.Since(StartTime),
		ID:        traveler.ID,
		Position:  traveler.Position,
		Symbol:    traveler.Symbol,
	}

	// Symulacja kroków
	for step := 0; step < nrOfSteps; step++ {
		delay := MinDelay + time.Duration(float64(MaxDelay-MinDelay)*rng.Float64())
		time.Sleep(delay)

		// Wykonanie kroku
		switch rng.Intn(4) {
		case 0:
			MoveUp(&traveler.Position)
		case 1:
			MoveDown(&traveler.Position)
		case 2:
			MoveLeft(&traveler.Position)
		case 3:
			MoveRight(&traveler.Position)
		}

		// Zapisanie śladu
		traces.Last++
		traces.TraceArray[traces.Last] = TraceType{
			TimeStamp: time.Since(StartTime),
			ID:        traveler.ID,
			Position:  traveler.Position,
			Symbol:    traveler.Symbol,
		}
	}

	// Wysłanie raportu do Printer
	reports <- traces
}

// Globalny czas startowy
var StartTime time.Time

func main() {
	// Inicjalizacja czasu startowego
	StartTime = time.Now()

	// Generowanie ziaren
	seeds := MakeSeeds(NrOfTravelers)

	// Kanał do przesyłania raportów
	reports := make(chan TracesSequenceType, NrOfTravelers)

	// WaitGroup do synchronizacji
	var wg sync.WaitGroup
	wg.Add(NrOfTravelers + 1) // +1 dla Printer

	// Wydrukowanie pierwszej linii z parametrami
	fmt.Printf("-1 %d %d %d\n", NrOfTravelers, BoardWidth, BoardHeight)

	// Uruchomienie Printer
	go Printer(reports, &wg)

	// Uruchomienie podróżnych
	symbol := 'A'
	for i := 0; i < NrOfTravelers; i++ {
		go TravelerTask(i, seeds[i], symbol, reports, &wg)
		symbol++
	}

	// Oczekiwanie na zakończenie wszystkich goroutines
	wg.Wait()
}