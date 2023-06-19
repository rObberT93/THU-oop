all: main-for-show.o
	g++ main-for-show.o -o main-for-show -std=c++11

main-for-show.o: main-for-show.cpp multidimarray.hpp capsule.hpp
	g++ -o main-for-show.o -c main-for-show.cpp -std=c++11

clean:
	del main-for-show *.o
