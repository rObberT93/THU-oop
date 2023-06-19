CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
OBJ = main.o Cow.o Farm.o
TARGET = main

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Cow.o: Cow.cpp
	$(CXX) $(CXXFLAGS) -c Cow.cpp

Farm.o: Farm.cpp
	$(CXX) $(CXXFLAGS) -c Farm.cpp

.PHONY: clean
clean:
	del *.o
