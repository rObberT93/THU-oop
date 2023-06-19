#include "vehicle.h"

Vehicle::Vehicle(int m_num, string m_engine): e(m_engine), w(m_num){
    //cout << "Finish building a vehicle with " << m_num << " wheels and a " << m_engine << " engine." << endl;
}

void Vehicle::describe() {
    cout << "Finish building a vehicle with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
    cout << "A vehicle with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
}