// Simple vector program
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>

using namespace std;


int main()
{
    ifstream data_file("data.txt"); // text file containing data
    istream_iterator<int> start(data_file), end;
    vector<int> data(start, end);

    int sum = 0;
    for (auto it = start; it != end; ++it)
        sum += *it;
    cout << "sum = " << sum << endl;
    cout << "average is = " << 1.0 * sum/data.size() << endl;
}
