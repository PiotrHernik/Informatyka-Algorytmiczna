# Nazwa projektu
TARGET = kompilator

# Kompilator i flagi
CXX = g++
CXXFLAGS = -std=c++17 -I./src/astUtilities -I./src/ast -I./src/functions -I./src/Commands

# Katalogi
SRC_DIR = main
AST_DIR = ast
FUNCTIONS_DIR = functions
UTILITIES_DIR = astUtilities

# Pliki źródłowe
SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/parser.cpp \
      $(SRC_DIR)/scanner.cpp \
      $(AST_DIR)/Args.cpp \
      $(AST_DIR)/ArgsDeclaration.cpp \
      $(AST_DIR)/Ast.cpp \
      $(AST_DIR)/Command.cpp \
      $(AST_DIR)/Condition.cpp \
      $(AST_DIR)/Declaration.cpp \
      $(AST_DIR)/Expression.cpp \
      $(AST_DIR)/Identifier.cpp \
      $(AST_DIR)/Main.cpp \
      $(AST_DIR)/ProcCall.cpp \
      $(AST_DIR)/ProcHead.cpp \
      $(AST_DIR)/Procedure.cpp \
      $(AST_DIR)/Value.cpp \
      SymbolTable/SymbolTable.cpp \
      $(FUNCTIONS_DIR)/validIdentifier.cpp \
      $(FUNCTIONS_DIR)/arithmetics.cpp \
      $(UTILITIES_DIR)/makeArgs.cpp \
      $(UTILITIES_DIR)/makeArgsDeclaration.cpp \
      $(UTILITIES_DIR)/makeCommands.cpp \
      $(UTILITIES_DIR)/makeDeclarations.cpp \
      $(UTILITIES_DIR)/makeIdentifier.cpp \
      $(UTILITIES_DIR)/makeProcCall.cpp \
      $(UTILITIES_DIR)/makeProcedures.cpp \
      $(UTILITIES_DIR)/makeProcHead.cpp \
      ErrorClass/Error.cpp

# Pliki Flex i Bison
FLEX_SOURCE = $(SRC_DIR)/scanner.lpp
FLEX_OUTPUT = $(SRC_DIR)/scanner.cpp

BISON_SOURCE = $(SRC_DIR)/parser.ypp
BISON_OUTPUT = $(SRC_DIR)/parser.cpp

# Reguły
.PHONY: all clean

# Domyślna reguła (kompilacja projektu)
all: $(TARGET)

# Generowanie pliku parser.cpp za pomocą Bison
$(BISON_OUTPUT): $(BISON_SOURCE)
	bison -d -o $@ -Wcounterexamples $<

# Generowanie pliku scanner.cpp za pomocą Flex
$(FLEX_OUTPUT): $(FLEX_SOURCE)
	flex -o $@ $<

# Kompilacja głównego pliku
$(TARGET): $(SRC) $(FLEX_OUTPUT) $(BISON_OUTPUT)
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

# Reguła czyszczenia plików wygenerowanych przez Flex i Bison
clean:
	rm -f $(TARGET) $(FLEX_OUTPUT) $(BISON_OUTPUT) $(SRC_DIR)/scanner.cpp $(SRC_DIR)/parser.cpp
