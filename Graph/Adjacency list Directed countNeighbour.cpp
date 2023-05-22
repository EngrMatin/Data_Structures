/* Directed unweighted Graph */

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

    void countNeighbour(int x)
    {
        cout<<x<<" : ";
        for(auto it=adj[x].begin(); it!=adj[x].end(); it++)
        {
            bool* visited = new bool[V];

            if(!visited[*it])
            {
                visited[*it] = true;
                int ans = *it;
                cout<<ans<<" ";

//                if(ans != NULL || ans != x)
//                {
//                    countNeighbour(ans);
//                }
            }
        }
        cout<<endl;
    }

    void DFS(int source)
    {
        static vector<bool> visited(V, false);
        //queue<int> Q;
        visited[source] = true;
        cout<<source<<" ";

        for(auto i: adj[source])
        {
            if(visited[i] != true)
            {
                DFS(i);
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

//    for(int i=0; i<V; i++)
//    {
//        g.countNeighbour(i);
//    }

    int k;
    cin>>k;

    //g.countNeighbour(k);
    cout<<endl<<endl;
    g.DFS(k);
    cout<<endl<<endl;

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
