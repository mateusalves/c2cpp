//read a series of words into a vector and sort them
#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    ifstream word_file("word.txt");
    istream_iterator<string> start(word_file), end;
    vector<string> words(start, end);

    cout << "\nwords as read\n";
    for( auto str: words )
        cout << str << "\t";
    sort(words.begin(), words.end());
    cout <<  "\n\nwords are sorted\n";
    for( auto str: words )
        cout << str << "\t";
    cout << endl;


    ifstream myin("data");
    istream_iterator<int> in(myin);
    istream_iterator<int> eos;
    cout << "\nSum of data is "  << accumulate(in, eos, 0) << endl;
}

