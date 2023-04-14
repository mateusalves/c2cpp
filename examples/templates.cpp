#include <iostream>

using namespace std;

// One for mySwap
template <class T>
inline void mySwap(T& d, T& s)
{
    T temp = d;
    d = s;
    s = temp;
}

// One function works for all data types. This would work
// even for user defined types if operator > is overload
template <typename T>
inline T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

// A template function to implement bubble sort.
// We can use this for any data type that supports
// comparison operator < and swap works for it
template <class T>
void bubbleSort(T a[], int n)
{
    for (int i = 0; i < n - 2; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j-i])
                mySwap(a[j], a[j - i]);
                //swap(a[j], a[j - i]);

}

int main(int argc, char **argv)
{
    cout << myMax<int>(3, 7) << endl;
    cout << myMax<double>(3.0, 7.0) << endl;
    cout << myMax<char>('g', 'e') << endl;


    int a[5] = {10, 50, 30, 40, 20};
    int n = sizeof(a)/sizeof(a[0]);


    bubbleSort<int>(a, n);

    cout << "sorted away: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
