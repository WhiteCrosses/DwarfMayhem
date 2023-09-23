# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall

# Include directories
INCLUDES = -I../include/SDL2

# Library directories
LIBDIRS = -L../lib

LIBS = -lSDL2

# Source files
SRC = main.cpp

# Output executable
OUT = my_program

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBDIRS) $(SRC) -o $(OUT) $(LIBS)

clean:
	rm -f $(OUT)

.PHONY: all clean

