#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 20;
const int INF = 999999;

// Add an undirected edge to the graph
void addEdge(int graph[N][N], int u, int v, int w)
{
    graph[u][v] = w;
    graph[v][u] = w;
}

// Dijkstra's shortest path algorithm
void dijkstra(int graph[N][N], int source, int destination)
{
    // Check for invalid vertices
    if (source < 0 || source >= N ||
        destination < 0 || destination >= N)
    {
        cout << "Error: Invalid vertex entered!" << endl;
        return;
    }

    int dist[N];
    int pred[N];
    bool visited[N];

    // Initialise distances, predecessors and visited flags
    for (int i = 0; i < N; i++)
    {
        dist[i] = INF;
        pred[i] = -1;
        visited[i] = false;
    }

    // Set source distance to zero
    dist[source] = 0;

    // Repeat until the destination is reached
    for (int count = 0; count < N; count++)
    {
        int u = -1;
        int minDist = INF;

        // Find the unvisited vertex with minimum distance
        for (int i = 0; i < N; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        // Stop if no reachable vertex remains
        if (u == -1)
            break;

        // Mark selected vertex as visited
        visited[u] = true;

        // Stop when destination is selected
        if (u == destination)
            break;

        // Examine all neighbours of the selected vertex
        for (int v = 0; v < N; v++)
        {
            if (graph[u][v] != INF && !visited[v])
            {
                int newLen = dist[u] + graph[u][v];

                // Check if a shorter path is found
                if (newLen < dist[v])
                {
                    dist[v] = newLen;
                    pred[v] = u;
                }
            }
        }
    }

    // Check whether the destination is reachable
    if (dist[destination] == INF)
    {
        cout << "No route exists from "
             << char(source + 'A') << " to "
             << char(destination + 'A') << "." << endl;
        return;
    }

    // Display shortest distance
    cout << "\nShortest distance from "
         << char(source + 'A') << " to "
         << char(destination + 'A') << " is: "
         << dist[destination] << " km" << endl;

    // Reconstruct the shortest path
    vector<int> path;

    for (int v = destination; v != -1; v = pred[v])
    {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    cout << "Shortest path: ";

    for (size_t i = 0; i < path.size(); i++)
    {
        cout << char(path[i] + 'A');

        if (i < path.size() - 1)
            cout << " -> ";
    }

    cout << endl;

    // Display distances and predecessors
    cout << "\nVertex\tDistance\tPredecessor\n";

    for (int i = 0; i < N; i++)
    {
        cout << char(i + 'A') << "\t";

        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << "\t\t";

        if (pred[i] == -1)
            cout << "-";
        else
            cout << char(pred[i] + 'A');

        cout << endl;
    }
}

int main()
{
    int graph[N][N];

    // Initialise the graph
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = INF;
        }
    }

    // Enter the edges and their weights
    addEdge(graph, 0, 1, 1);    // A-B
    addEdge(graph, 0, 2, 2);    // A-C
    addEdge(graph, 1, 2, 3);    // B-C
    addEdge(graph, 1, 3, 4);    // B-D
    addEdge(graph, 2, 3, 4);    // C-D
    addEdge(graph, 2, 7, 8);    // C-H
    addEdge(graph, 3, 4, 5);    // D-E
    addEdge(graph, 4, 6, 3);    // E-G
    addEdge(graph, 4, 7, 5);    // E-H
    addEdge(graph, 7, 6, 5);    // H-G
    addEdge(graph, 7, 5, 13);   // H-F
    addEdge(graph, 7, 11, 14);  // H-L
    addEdge(graph, 6, 5, 7);    // G-F
    addEdge(graph, 5, 10, 3);   // F-K
    addEdge(graph, 5, 8, 8);    // F-I
    addEdge(graph, 8, 10, 12);  // I-K
    addEdge(graph, 8, 15, 13);  // I-P
    addEdge(graph, 8, 9, 3);    // I-J
    addEdge(graph, 9, 11, 3);   // J-L
    addEdge(graph, 9, 12, 1);   // J-M
    addEdge(graph, 11, 13, 1);  // L-N
    addEdge(graph, 11, 12, 4);  // L-M
    addEdge(graph, 15, 14, 2);  // P-O
    addEdge(graph, 15, 12, 3);  // P-M
    addEdge(graph, 15, 16, 4);  // P-Q
    addEdge(graph, 13, 16, 15); // N-Q
    addEdge(graph, 10, 19, 8);  // K-T
    addEdge(graph, 19, 18, 5);  // T-S
    addEdge(graph, 18, 17, 7);  // S-R
    addEdge(graph, 17, 14, 6);  // R-O
    addEdge(graph, 14, 16, 1);  // O-Q

    // TEST 3: Indirect route shorter than direct edge (H to F)
    dijkstra(graph, 7, 5);

    return 0;
}
