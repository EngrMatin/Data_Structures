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

    void printNeighbour(int chk)
    {
        cout<<chk<<" : ";
        for(auto i=adj[chk].begin(); i!=adj[chk].end(); i++)  //pointer iterator i
        {
            cout<<*i<<" ";
        }
        cout<<endl;
    }

    void BFS(int source)
    {
        vector<bool> visited(V, false);
        queue<int> Q;
        visited[source] = true;
        Q.push(source);

        while(!Q.empty())
        {
            int u = Q.front();
            cout<<u<<" ";
            Q.pop();

            for(auto i: adj[u])
            {
                if(visited[i] != true)
                {
                    visited[i] = true;
                    Q.push(i);
                }
            }
        }
    }
};

int main()
{
    int V, E, source;
    cin>>V>>E>>source;

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

    cout<<endl<<endl;
    g.BFS(source);
    cout<<endl<<endl;

    return 0;
}

/*

7 10 0
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

*/
