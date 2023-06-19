all: main.o
	g++ main.o -o main -std=c++11

main.o:main.cpp Calculator.h LevelStrategy.h PerformStrategy.h
	g++ -o main.o -c main.cpp -std=c++11

clean:
	del main *.o *.exe