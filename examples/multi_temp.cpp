#include <iostream>

using namespace std;

template <class T1, class T2>
void copy(const T1 source[], T2 destination[], int size)
{
    for (int i = 0; i < size; ++i)
        destination[i] = static_cast<T2>(source[i]);
}

int main(int argc, char **argv)
{
    double a[] = {1.0, 2.6, 3.0};
    int b[3];
    copy(a, b, 3);
    cout << b[1] << endl;
}

