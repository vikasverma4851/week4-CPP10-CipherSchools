#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Function to perform BFS traversal starting from a given vertex
void BFS(const vector<vector<int>>& graph, int start) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false); // Keeps track of visited vertices
    queue<int> q; // Queue for BFS traversal

    // Enqueue the starting vertex and mark it as visited
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " "; // Process the current vertex (You can do any other operation here)

        // Explore all adjacent vertices of the current vertex
        for (int adjacentVertex : graph[currentVertex]) {
            // If the adjacent vertex is not visited, enqueue it and mark it as visited
            if (!visited[adjacentVertex]) {
                q.push(adjacentVertex);
                visited[adjacentVertex] = true;
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numVertices);

    cout << "Enter the edges (source and destination vertices):\n";
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph[src].push_back(dest);
        graph[dest].push_back(src); // Add this line for undirected graphs
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS traversal starting from vertex " << startVertex << ":\n";
    BFS(graph, startVertex);

    return 0;
}
