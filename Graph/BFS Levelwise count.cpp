// C++ Program to print count of nodes at given level.
#include <iostream>
#include <list>
using namespace std;

class Graph              // This class represents a directed graph using adjacency list representation
{
    int V;               // No. of vertices
    list<int>* adj;      // Pointer to an array containing adjacency lists

public:
    Graph(int V)          // Constructor
    {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w)     // function to add an edge to graph
    {
        adj[v].push_back(w);               // Add w to v’s list.
        adj[w].push_back(v);               // Add v to w's list.
    }

    void BFS(int s, int l)          // Returns count of nodes at level l from given source.
    {
        bool* visited = new bool[V];         // Mark all the vertices as not visited
        int level[V];

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            level[i] = 0;
        }

        list<int> queue;                      // Create a queue for BFS

        visited[s] = true;                   // Mark the current node as visited and enqueue it
        queue.push_back(s);
        level[s] = 0;

        while (!queue.empty())
        {
            s = queue.front();              // Dequeue a vertex from queue and print it
            queue.pop_front();

                            // Get all adjacent vertices of the dequeued vertex s. If a adjacent has not been visited, then mark it visited and enqueue it
            for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            {
                if (!visited[*i])
                {
                    level[*i] = level[s] + 1;    // Setting the level of each node with an increment in the level of parent node
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }

        //int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (level[i] == l)
            {
                cout<<i<<" ";
                //count++;
            }
        }

        //return count;
    }
};

int main()
{
    int V, E;
    cin>>V>>E;

    Graph g(V);

    for(int i=0; i<E; i++)
    {
        int v, w;
        cin>>v>>w;

        g.addEdge(v, w);
    }

    int level;
    cin>>level;

    g.BFS(0, level);

    return 0;
}
