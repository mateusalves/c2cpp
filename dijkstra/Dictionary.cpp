#include <iostream>
#include <memory>
#include <set>
#include <queue>

#include "Dictionary.h"

Dictionary::Dictionary(int wordSize)
    : _values(), _valuePositions(), _adjacencyList(), _wordSize(wordSize)
{
}

const std::vector<std::vector<bool>>& Dictionary::AdjList()
{
    return _adjacencyList;
}

Dictionary& Dictionary::operator=(const Dictionary& rhs)
{
    if(&rhs != this)
    {
        _adjacencyList = rhs._adjacencyList;
        _valuePositions = rhs._valuePositions;
        _values = rhs._values;
        _wordSize = rhs._wordSize;
    }
    return *this;
}

// True if the words a and b differ by just one character
bool diffByOne(const std::string &a, const std::string &b)
{
    if (a.size() != b.size())
        return false;

    int ndiff = 0;

    for (unsigned int i = 0; i < a.length(); ++i)
    {
        if (a[i] != b[i])
            ndiff++;
    }
    return ndiff == 1;
}

bool Dictionary::Contains(const std::string &s)
{
    return _valuePositions.find(s) != _valuePositions.end();
}


int Dictionary::ElemPosition(const std::string &s)
{
    return _valuePositions[s];
}


void Dictionary::AddElement(const std::string &s)
{
    if(s.size() != _wordSize)
        throw std::runtime_error("invalid string size");
    _values.push_back(s);
    _valuePositions[s] = (int)_values.size() - 1;
    std::cout << " added " << s << std::endl;
}

std::string Dictionary::ElemAtPos(int i)
{
    return _values[i];
}

void Dictionary::BuildAdjancencyMatrix()
{
    _adjacencyList.clear();
    int n = (int)_values.size();
    for (int i = 0; i < n; ++i)
    {
        _adjacencyList.push_back(std::vector<bool>(n));
        for (int j = 0; j < n; ++j)
        {
            if (diffByOne(_values[i], _values[j]))
                _adjacencyList[i][j] = 1;
        }
    }
}


