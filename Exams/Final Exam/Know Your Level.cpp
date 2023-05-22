#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int>* adj;

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

    void BFS(int s, int lev)
    {
        bool* visited = new bool[V];
        int level[V];

        for(int i=0; i<V; i++)
        {
            visited[i] = false;
            level[i] = 0;
        }

        list<int> queue;

        visited[s] = true;
        queue.push_back(s);
        level[s] = 0;

        while (!queue.empty())
        {
            s = queue.front();
            queue.pop_front();

            for(auto it = adj[s].begin(); it != adj[s].end(); ++it)
            {
                if(!visited[*it])
                {
                    level[*it] = level[s] + 1;
                    visited[*it] = true;
                    queue.push_back(*it);
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
2
Output: 3 4 6

6 5
0 1
0 2
1 3
2 4
2 5
2
Output: 3 4 5

6 7
0 1
0 2
0 3
1 5
3 2
5 4
2 4
2

Output: 5 4


3 3
0 1
1 2
2 0
1

output: 1 2

6 3
0 1
1 3
3 5
4
Output: 0

6 7
0 1
0 2
0 3
0 5
1 3
2 5
3 4
1

1 2 3 5

*/
