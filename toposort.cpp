#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void doDFS(vector<vector<int>> adjList, vector<bool> &visited, int idx, stack<int> &st) {
    visited[idx] = true;

    for(auto i : adjList[idx]) {
        if(!visited[i]) {
            doDFS(adjList, visited, i, st);
        }
    }

    st.push(idx);
}

vector<int> getTopoSort(vector<vector<int>> adjList, const int N) {
    vector<int> out;

    // visited list
    vector<bool> visited(N, false);

    stack<int> st;

    // do the DFS search for all nodes and its adjacencies
    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            doDFS(adjList, visited, i, st);
        }
    }

    while(!st.empty()) {
        out.push_back(st.top());
        st.pop();
    }

    return out;
}

int main() {
    cout << "Print topological sort of vertices" << endl;
    vector<vector<int>> adjList = {{}, {}, {3}, {1}, {0,1}, {0,2}};
    const int N = 6;
    
    vector<int> topoSort = getTopoSort(adjList, N);
    for(auto e : topoSort)
        cout << e << "  ";
    cout << endl;

    if(!topoSort.empty() and !adjList.empty())
        cout << "Success";

    return 0;
}