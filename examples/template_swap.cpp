#include <iostream>
#include <complex>

using namespace std;

template <class summable>
// summable is the generic type
summable sum(const summable data[], int size, summable s=0)
{
    for (int i = 0; i < size; ++i)
        s += data[i];
    // += must work for summable
    return s;
}

template <class T>
inline void myswap(T &d, T &s)
{
    T temp = d;
    d = s;
    s = temp;
}

int main(int argc, char **argv)
{
    int m = 5, n = 10;
    double x = 5.3, y = 10.6;
    complex<double> r(2.4, 3.5), s(3.4, 6.7);

    cout << "inputs: " << m << ", " << n << endl;
    myswap(m, n);
    cout << "outputs: " << m << ", " << n << endl;

    cout << "complex inputs: " << r << ", " << s << endl;
    myswap(r, s);
    cout << "complex outputs: " << r << ", " << s << endl;

    cout << "double inputs: " << x << ", " << y << endl;
    myswap(x, y);
    cout << "double outputs: " << x << ", " << y << endl;
}

