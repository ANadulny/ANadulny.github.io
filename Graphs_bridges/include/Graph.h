#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

namespace AISDI_PROJECT
{

class Graph
{
    private:
        std::vector< std::vector<int> > graph;
        std::vector<bool> checked;
        int vertexCount = 0;

    public:
        Graph(int vertexCount, std::vector< std::pair<int,int> > edges):vertexCount(vertexCount)
        {
            graph.resize(vertexCount);
            checked.resize(vertexCount);

            for(auto it:edges)
            {
                int v = it.first, u = it.second;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        ~Graph() {}

        bool lockEdgeConnected(std::pair<int,int> edge)
        {
            for(auto it:checked)
                it = false;

            checked[edge.first] = true;
            checked[edge.second] = true;

            return connected();
        }

    private:
        bool connected()
        {
            int Counter = 0;
            for(int i = 0; i < vertexCount; i++)
            {
                if( !checked[i] )
                {
                    Counter++;
                    dfs_visit(i);
                }
            }
            return (Counter == 1);
        }

        void dfs_visit(int u)
        {
            checked[u]=true;
            for(std::vector<int>::iterator it = graph[u].begin(); it != graph[u].end(); it++)
            {
                int v = *it;
                if( !checked[v] )
                    dfs_visit(v);
            }
        }
};

}
#endif // GRAPH_H
