#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> g, int N, int start, vector<bool> visited) {

    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int front = q.front();
        visited[front] = true;
        cout << front << "  ";
        q.pop();

        for(auto i : g[front]) {
            if(!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void dfs(vector<vector<int>> g, int N, int start, vector<bool> &visited) {
    if(visited[start]) return;
    cout << start << "  ";
    visited[start] = true;
    vector<int> tmp = g[start];
    for(auto i : tmp) {
        dfs(g, N, i, visited);
    }
}

bool checkIfCycle(vector<vector<int>> g, int N, int start, vector<bool> &visited) {
    
    queue<pair<int, int>> q;
    q.push({start, -1});
    
    while(!q.empty()) {
        pair<int, int> curr_prev = q.front();
        q.pop();

        visited[curr_prev.first] = true;

        for(auto i : g[curr_prev.first]) {
            if(!visited[i]) {
                visited[i] = true;
                q.push({i, curr_prev.first});
            }
            else {
                if(i != curr_prev.second)
                    return true;
            }

        }
    }
    
    return false;
}


bool isCyclic(vector<vector<int>> g, int N, int start, vector<bool> &visited) {
    
    // logic: we keep track of the current node value and its previous i.e parent node
    // value and iterate. If any node comes across as 'visited' but whose parent 
    // node is different from current node, then it must have been visited via another
    // path - this indicates a cycle in the graph

    for(int i = 0; i < N; i++) {
        if(checkIfCycle(g, N, start, visited))
            return true;
    }
    
    return false;
}

int main() {
    cout << "Graph traversal using BFS and DFS" << endl;
    vector<vector<int>> g = {{2, 4, 5}, {2,3,4}, {0,1,5,6}, {1,6}, {0,1}, {0,2}, {2,3}};//{{1, 4}, {2, 3, 4}, {3}, {4}, {0,1}};
    const int N = 7;
    vector<bool> visited(N, false);
    int start = 0;
    cout << "BFS: ";
    bfs(g, N, start, visited);
    visited.resize(N, false);
    cout << endl << "DFS: ";
    dfs(g, N, start, visited);
    visited.resize(N, false);
    cout << endl;
    cout << "Iscyclic: " << isCyclic(g, N, 0, visited) << endl;
    return 0;
}