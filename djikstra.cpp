#include <iostream>
#include <vector>
using namespace std;

int getMinDistIdx(vector<bool> visited, vector<int> dist) {
    int minD = INT_MAX;
    int minIdx = -1;
    for(int v = 0; v < dist.size(); v++){
        if(!visited[v] && dist[v] < minD) {
            minD = dist[v];
            minIdx = v;
        }
    }
    return minIdx;
}

void printShortestPath(vector<vector<int>> &graph, int src) {
    int numV = graph.size();

    // have a visited aar
    vector<bool> visited(numV, false);

    // have a dist vector
    vector<int> dist(numV, INT_MAX);

    // always mark visted of src = true
    visited[src] = true;
    dist[src] = 0;

    // first fill out direct edges from src vertex
    for(int i = 0; i < numV; i++) {
        if(graph[src][i] != 0)
            dist[i] = graph[src][i];
    }

    // proceed for other vertices
    for(int i = 0; i < numV - 1; i++) {
        int u = getMinDistIdx(visited, dist);

        visited[u] = true;

        for(int v = 0; v < numV; v++) {
            if(!visited[v] && (graph[u][v] != 0) && (dist[u] + graph[u][v] < dist[v])) {
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for(int v : dist)
        cout << v << "  ";
    
    cout << endl;

}

int main() {
    
     vector<vector<int>> graph =        { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    printShortestPath(graph, 0);
 
    return 0;
}