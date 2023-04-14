#pragma once

#include <vector>
#include <string>

class Dictionary;

class StringProduction
{
    public:
        StringProduction(Dictionary& d);
        StringProduction(const StringProduction& other);
        ~StringProduction() = default;
        StringProduction &operator=(const StringProduction& rhs);

        bool Produces(const std::string& src, const std::string& dest,
                std::vector<std::string>& path);
        void Shortest_path(int v, int dest, int n, std::vector<std::string>& path);
        std::vector<int> RecoverPath(int src, int dest, const std::vector<int>& P,
                std::vector<int>& path);
    private:
        Dictionary& _dic;
};
