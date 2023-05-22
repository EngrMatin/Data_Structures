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
    }

    void DFS(int source, int &count)
    {
        static vector<bool> visited(V, false);
        visited[source] = true;

        count++;

        for(auto i: adj[source])
        {
            if(visited[i] != true)
            {
                DFS(i, count);
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

    int k;
    cin>>k;

    int count=0;
    g.DFS(k, count);
    cout<<count-1<<endl;

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
2 3
3 0
4 5
2


*/
