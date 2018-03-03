#include <iostream>
#include "include/Graph.h"


using Graph = AISDI_PROJECT::Graph;

int main()
{
    int vertexCount;
    std::cin >> vertexCount;

    if( vertexCount <= 3)
        return 0;

    std::vector< std::pair<int,int> > edges;

    int u, v;
    while(std::cin >> v >> u)
    {
        std::pair<int,int> newEdge = std::make_pair(v, u);
        edges.push_back(newEdge);
    }

    Graph myGraph(vertexCount, edges);

    for(auto it:edges)
    {
        if(!myGraph.lockEdgeConnected(it))
            std::cout << it.first << " " << it.second << std::endl;
    }

    return 0;
}

