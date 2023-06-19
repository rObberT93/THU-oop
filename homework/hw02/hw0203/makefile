CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

main: main.o Matrix.o
	$(CXX) $(CXXFLAGS) -o main main.o Matrix.o

main.o: main.cpp Matrix.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Example.o: Matrix.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c Matrix.cpp

clean:
	del main.o Matrix.o main.exe
