#include <iostream>

#include "StringProduction.h"
#include "Dictionary.h"



//main function is a test case for the algorithm

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "prog word1 word2" << std::endl;
        return 1;
    }
    Dictionary dic(3);
    dic.AddElement("lob");
    dic.AddElement("dag");
    dic.AddElement("log");
    dic.AddElement("car");
    dic.AddElement("dog");
    dic.AddElement("cat");
    dic.AddElement("cob");
    dic.AddElement("cab");
    dic.AddElement("cag");

    dic.BuildAdjancencyMatrix();

    std::vector<std::string> path;
    StringProduction sp(dic);
    if (sp.Produces(argv[1], argv[2], path))
    {
        std::cout << "-- The first string produces the second" << std::endl;
        std::cout << "-- that path has size: " <<  path.size() << std::endl;

        for(size_t i = 0; i < path.size(); ++i)
        {
            std::cout << path[i] << "; ";
        }
    }
    else
    {
        std::cout << "The second string does not produce the secon" << std::endl;
    }
    return 0;
}
