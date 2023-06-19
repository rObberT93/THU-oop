class Student{
private:
const int id;
double gpa;
public:
Student(int _id): id(_id), gpa(0.0) {} // (A)
// Student(int _id) {id = _id; gpa = 0.0;}
    int getId() const {
    return id;
}
    void updateGpa(double _gpa) {
        gpa = _gpa;
    }
    double getGpa() {
        return gpa;
    }
};

int main(){
    Student alice(1);
    alice.getId();
    alice.updateGpa(4.0);
    alice.getGpa();

    const Student bob(2);
    bob.getId();
    //bob.getGpa();

    return 0;
}
