void f(int& x) {
}

void f(int&& x) {
    int& y = x; //(1)
    const int& z = y+1; //(2)
    //int& w=2; //(3)
    f(z); //(4)
}
