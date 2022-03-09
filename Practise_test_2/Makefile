CC=g++
CXXFLAGS=-Wall -O3 -pedantic
LDLIBS=-llapack
TARGET=main

default: $(TARGET)
all: $(TARGET)

$(TARGET): $(TARGET).o

.PHONY: clean doc

run: $(TARGET)
	./$(TARGET)

doc:
	doxygen Doxyfile

clean:
	rm -rf $(TARGET) *.o