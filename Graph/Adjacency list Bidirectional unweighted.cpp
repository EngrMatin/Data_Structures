/* Bi-directional unweighted Graph */

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int> [V];
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printNeighbour(int x)
    {
        cout<<x<<" : ";
        for(auto it=adj[x].begin(); it!=adj[x].end(); it++)
        {
            cout<<*it<<" ";
        }

        cout<<endl;
    }
};

int main()
{
    int V, E;
    cin>>V>>E;

    Graph g(V);

    for(int i=0; i<E; i++)
    {
        int u, v;
        cin>>u>>v;

        g.addEdge(u, v);
    }

    for(int i=0; i<V; i++)
    {
        g.printNeighbour(i);
    }

    return 0;
}

/*

7 10
0 1
0 2
0 5
1 3
2 3
2 5
3 6
6 5
6 4
5 4


6 5
0 1
0 2
0 3
2 3
4 5


*/
