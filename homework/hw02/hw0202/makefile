CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

main: main.o Example.o
	$(CXX) $(CXXFLAGS) -o main main.o Example.o

main.o: main.cpp Example.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Example.o: Example.cpp Example.h
	$(CXX) $(CXXFLAGS) -c Example.cpp

clean:
	del main.o Example.o main.exe
