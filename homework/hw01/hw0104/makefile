CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

main: main.o chef.o manager.o
	$(CXX) $(CXXFLAGS) -o main main.o chef.o manager.o

main.o: main.cpp chef.h manager.h
	$(CXX) $(CXXFLAGS) -c main.cpp

chef.o: chef.cpp chef.h
	$(CXX) $(CXXFLAGS) -c chef.cpp

manager.o: manager.cpp manager.h
	$(CXX) $(CXXFLAGS) -c manager.cpp

clean:
	del main.o manager.o chef.o main.exe
