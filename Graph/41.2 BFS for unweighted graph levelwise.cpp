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

    void BFS(int source, int lev)
    {
        vector<bool> visited(V, false);
        int level[V];
        for(int i = 0; i < V; i++)
        {
            level[i] = 0;
        }

        queue<int> Q;
        visited[source] = true;
        Q.push(source);

        while(!Q.empty())
        {
            int temp = Q.front();
            Q.pop();

            for(auto i: adj[temp])
            {
                if(visited[i] != true)
                {
                    visited[i] = true;
                    level[i] = level[temp] + 1;
                    Q.push(i);
                }
            }
        }

        for(int i=0; i<V; i++)
        {
            if(level[i] == lev)
            {
                cout<<i<<" ";
            }
        }
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

    int level;
    cin>>level;

    g.BFS(0, level);

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
1

6 5
0 1
0 2
1 3
2 4
2 5
2



*/
