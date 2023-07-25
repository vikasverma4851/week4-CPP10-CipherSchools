#include <iostream>
#include <vector>

using namespace std;

bool isCycleUtil(const vector<vector<int>>& graph, int vertex, int parent, vector<bool>& visited) {
    visited[vertex] = true;

    // Traverse all adjacent vertices of the current vertex
    for (int adjacentVertex : graph[vertex]) {
        if (!visited[adjacentVertex]) {
            // If the adjacent vertex is not visited, recursively check for cycle
            if (isCycleUtil(graph, adjacentVertex, vertex, visited)) {
                return true;
            }
        } else if (adjacentVertex != parent) {
            // If the adjacent vertex is visited and not the parent of the current vertex, there is a cycle
            return true;
        }
    }

    return false;
}

bool isCycle(const vector<vector<int>>& graph) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);

    // Iterate through all vertices to check for cycle
    for (int i = 0; i < numVertices; ++i) {
        if (!visited[i]) {
            if (isCycleUtil(graph, i, -1, visited)) {
                return true;
            }
        }
    }

    return false;
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

    if (isCycle(graph)) {
        cout << "The graph contains a cycle.\n";
    } else {
        cout << "The graph does not contain a cycle.\n";
    }

    return 0;
}
