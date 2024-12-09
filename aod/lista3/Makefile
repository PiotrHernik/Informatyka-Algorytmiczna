# Kompilator i flagi
CXX = g++
CXXFLAGS = -Wall -O3 -Wextra 

# Nazwa programu
TARGET = program

# Pliki źródłowe i obiekty
SRC = main2.cpp Dial.cpp Dijkstra.cpp Graph.cpp RadixHeapAlgorithm.cpp Parser.cpp
OBJ = $(SRC:.cpp=.o)

# Domyślny cel
all: $(TARGET)

# Reguła tworzenia pliku wykonywalnego
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Reguła tworzenia plików obiektowych
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Czyszczenie
clean:
	rm -f $(OBJ) $(TARGET)

deleteresults:
	rm -f *.res
