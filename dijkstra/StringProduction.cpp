#include <algorithm>
#include <climits>
#include <map>
#include <set>

#include "StringProduction.h"
#include "Dictionary.h"


StringProduction::StringProduction(Dictionary& d)
    : _dic(d)
{
}

StringProduction::StringProduction(const StringProduction & other)
    : _dic(other._dic)
{
}

StringProduction& StringProduction::operator=(const StringProduction &rhs)
{
    if (&rhs != this)
    {
        _dic = rhs._dic;
    }
    return *this;
}

// Recovers the path  from a list of preivous nodes (P)
std::vector<int> StringProduction::RecoverPath(int src, int dest,
        const std::vector<int>& P, std::vector<int>& path)
{
    int v = dest;

    while (v != src)
    {
        path.push_back(v);
        v = P[v];
    }
    path.push_back(src);
    std::reverse(path.begin(), path.end());
    return path;
}

// Computes the shortest path.
// Node v is the source, dest is destination. If the path can be found, it is stored on parameter path
void StringProduction::Shortest_path(int v, int dest, int n, std::vector<std::string> &path)
{
    const std::vector<std::vector<bool>>& A = _dic.AdjList(); // get the adjacency matrix

    path.clear();

    std::vector<int> dist(n, 0);
    std::vector<int> prev(n, 0);
    std::set<int> Q;            // set of nodes
    const int INF = INT_MAX;    // a large number

    // Initialize the set of distances and the set of nodes
    for (int i = 0; i < n; ++i)
    {
        Q.insert(i);
        if (i != v)
            dist[i] = INF;
    }
    // This is Dijkstra's algorithm
    while (!Q.empty())
    {
        int min = INF;
        int u = -1;

        for (std::set<int>::iterator it = Q.begin(); it != Q.end(); ++it)
        {
            // FInd the minimum value in queue
            if (dist[*it] < min)
            {
                min = dist[*it];
                u = *it;
            }
        }
        Q.erase(u); // remove min vertex u from set

        // Relaxation step
        for (int i = 0; i < n; ++i)
        {
            if (A[u][i]) // this is a neighbor
            {
                int d = dist[u] + 1;
                if (d < dist[i])
                {
                    dist[i] = d;
                    prev[i] = u;
                }
            }
        }
    }

    // Recover the path from vector prev
    std::vector<int> npath;
    RecoverPath(v, dest, prev, npath);
    for (auto elem : npath)
        path.push_back(_dic.ElemAtPos(elem));

}

// Returns true if the word src produces dest using the
// dictionary dic. If true, then the path will contain the path
// between src and dest.
bool StringProduction::Produces(const std::string &src, const std::string &dest, std::vector<std::string> &path)
{
    if(!_dic.Contains(src) || !_dic.Contains(dest))
        return false;

    Shortest_path(_dic.ElemPosition(src), _dic.ElemPosition(dest), _dic.Size(), path);
    return path.size() > 0;
}





