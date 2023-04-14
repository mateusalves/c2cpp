#pragma once

#include <string>
#include <vector>
#include <map>


// Stores the words in the dictionary and provides an adjacency matrix for the words
class Dictionary
{
    public:
        Dictionary(int wordSize);
        ~Dictionary() = default;
        Dictionary &operator=(const Dictionary& rhs); // not implemented
    private:
        Dictionary(const Dictionary& other); // not implemented
    public:
        void AddElement(const std::string& s);
        void BuildAdjancencyMatrix();
        bool Contains(const std::string& s);
        const std::vector<std::vector<bool>>& AdjList();
        int ElemPosition(const std::string& s);
        int Size() {return (int)_values.size();}
        std::string ElemAtPos(int i);
    private:
        std::vector<std::string> _values;
        std::map<std::string, int> _valuePositions;
        std::vector<std::vector<bool>> _adjacencyList;
        int _wordSize;
};
