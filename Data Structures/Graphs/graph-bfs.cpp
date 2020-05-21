/* Graph can be represented in 2 ways -
 1. Adjacency Matrix - 2D matrix containing rows and columns as vertices
 2. Adjacency List - Array of list where each array element is vertex & its list elements are neighbours

-  BFS - Breadth First Search or level Order Serach in graph is used to find the shortest path between the 2 vertices
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void AddEdge(int v, int w);
    void BFS(int source);
};

Graph::Graph(int V)
{
    this->V = V;
    this->adj = new list<int>[V];
}

void Graph::AddEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list
}

void Graph::BFS(int source)
{
    // Take a visited array
    // Mark each element in visited array as false
    // Take a queue
    // Enqueue source into queue
    // mark the element visited
    // loop till the queue is empty
    // take out the element
    // print it
    // run the loop
    // for each neighbour of popped element, mark it visited
    // put it into queue

    bool *visited = new bool[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    queue<int> que;

    visited[source] = true;
    que.push(source);

    list<int>::iterator i;
    while (!que.empty())
    {

        source = que.front();

        cout << source << " ";
        que.pop();

        for (i = adj[source].begin(); i != adj[source].end(); ++i)
        {
            // cout << "checking for value " << *i << endl;
            if (!visited[*i])
            {
                visited[*i] = true;
                // cout << "putting into que " << *i << endl;
                que.push(*i);
            }
        }
    }
}

int main()
{

    // A graph can be represented as the array of vector or vector of vector
    // naming them respectively as adjacency list and adjacency matrix

    //create graph and add 4 vertices to it.
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);

    cout << "Graph is created, calling BFS now" << endl;
    g.BFS(2); // Calling BFS to traverse the graph

    return 0;
}
