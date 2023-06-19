CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

main: main.o Object.o Splash.o
	$(CXX) $(CXXFLAGS) -o main main.o Object.o Splash.o

main.o: main.cpp Object.h Splash.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Object.o: Object.cpp Object.h
	$(CXX) $(CXXFLAGS) -c Object.cpp

Splash.o: Splash.cpp Splash.h
	$(CXX) $(CXXFLAGS) -c Splash.cpp

clean:
	del main.o Splash.o Object.o main.exe