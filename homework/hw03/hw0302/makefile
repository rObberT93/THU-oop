CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

main: main.o car.o motor.o vehicle.o engine.o wheel.o
	$(CXX) $(CXXFLAGS) -o main main.o car.o motor.o vehicle.o engine.o wheel.o

main.o: main.cpp car.h motor.h vehicle.h engine.h wheel.h
	$(CXX) $(CXXFLAGS) -c main.cpp

car.o: car.cpp car.h
	$(CXX) $(CXXFLAGS) -c car.cpp

motor.o: motor.cpp motor.h
	$(CXX) $(CXXFLAGS) -c motor.cpp

vehicle.o: vehicle.cpp vehicle.h
	$(CXX) $(CXXFLAGS) -c vehicle.cpp

engine.o: engine.cpp engine.h
	$(CXX) $(CXXFLAGS) -c engine.cpp

wheel.o: wheel.cpp wheel.h
	$(CXX) $(CXXFLAGS) -c wheel.cpp

clean:
	del -f main.exe *.o