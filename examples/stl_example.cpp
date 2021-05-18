// Simple STL vector program
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(100); //allocate space

    for (int i = 0; i< 100 ; ++i)
        v[i] = i; //index thru like an array
    for (vector<int>::iterator p = v.begin(); p != v.end(); ++p)
        cout << *p << '\t';
    // vector<int>::iterator p == auto p (auto is used to declare types that can be deduced from context)
    for (auto p = v.begin(); p != v.end(); ++p)
        cout << *p << '\t';
    cout << endl;
}
