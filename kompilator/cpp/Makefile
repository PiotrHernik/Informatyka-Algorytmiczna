# Nazwa projektu
TARGET = compiler

# Pliki źródłowe
SRC = main.cpp parser.cpp scanner.cpp ast.cpp SymbolTable.cpp functions/validIdentifier.cpp Commands/CommandIf.cpp Commands/CommandIfElse.cpp

# Kompilator i flagi
CXX = g++
CXXFLAGS = -std=c++17

# Pliki Flex i Bison
FLEX_SOURCE = scanner.lpp
FLEX_OUTPUT = scanner.cpp

BISON_SOURCE = parser.ypp
BISON_OUTPUT = parser.cpp

# Reguły
.PHONY: all clean

all: $(TARGET)

$(BISON_OUTPUT): $(BISON_SOURCE)
	bison -d -o $@ -Wcounterexamples $<

$(FLEX_OUTPUT): $(FLEX_SOURCE)
	flex -o $@ $<

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

clean:
	rm -f $(TARGET) scanner.cpp parser.cpp
