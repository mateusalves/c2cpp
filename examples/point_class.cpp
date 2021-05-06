#include <iostream>
using namespace std;

class point{
    public:
        point(double x=0.0, double y=0.0):x(x),y(y){} //constructor
        //point(){x = y = 0.0;}
        //point(){this->x=0.0; this->y=0.0}
        //point():x(0.0),y(0.0){}
        double getx() const {return x;}
        double gety() const {return y;}
        void setx (double v) {x = v;}
        void sety (double v) {y = v;}
    private:
        double x, y;
};

point operator+ (point &p1, point &p2){
    point sum;
    sum.setx(p1.getx() + p2.getx());
    sum.sety(p1.gety() + p2.gety());
    return sum;
}

ostream& operator<< (ostream& out, const point& p){
    out << "(" << p.getx() << ", " << p.gety() << ")";
    return out;
}
// usual signature for overloading ostream &operator<<
// (ostream &out, const my_type &v)
// both arguments are passed by reference
// my_type is passed with a const modifier
// so as not to be modified

int main(int argc, char **argv){
    point a, b, c;
    a.setx(3.5);
    a.sety(2.5);
    b.setx(2.5);
    b.sety(4.5);
    cout << "a = " << a << " b = " << b << endl;
    cout << "sum = " << a + b << endl;
}
