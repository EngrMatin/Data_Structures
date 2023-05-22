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

    void countNeighbour(int x)
    {
        int count=0;
        for(auto it=adj[x].begin(); it!=adj[x].end(); it++)
        {
            count++;
        }
        cout<<count<<endl;
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

    int k;
    cin>>k;

    g.countNeighbour(k);

    return 0;
}

/*


6 5
0 1
0 2
0 3
2 3
4 5
2


*/

