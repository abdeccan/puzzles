#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    vector<vector<int>> _adjList;
    int _v;

    public:

    Graph(int V) : _v(V) {
        _adjList.resize(2 * _v);    // through out we use 2 * _v because potentially there can be intermediate vertices in all edges
    }

    int printShortestPath(vector<int> parent, int n) {
        static int len = 0;

        if(parent[n] == -1) {
            cout << "Path len = " << len << endl << " Path is " << n << "  ";
            return len;
        }

        len++;
        
        printShortestPath(parent, parent[n]);

        if(n < _v) 
            cout << n << "  ";

        return len;
    }

    int getShortestPath(int s, int d) {
        vector<int> parent(2 * _v, -1); // parent is needed to trace the path
        vector<bool> visited(2 * _v, false);

        queue<int> q;
        q.push(s);
        visited[s] = true;

        while(!q.empty()) {
            int front = q.front();

            // have we reached the destination?
            if(front == d) {
                return printShortestPath(parent, front);
            }
            
            q.pop();
            
            // check the adjacencies
            for(auto i : _adjList[front]) {
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                    parent[i] = front;
                }
            }
        }

        return 0;
    }

    /*
        Since this is a weighted and directional graph, we cannot directly use BFS search.
        Other forms like Djikstra can be used but it would be more complex for Time. Since the
        requirement here is to do in O(V + E), we have to use BFS. To do BFS, we will modify the
        graph slightly so that an edge of value 2 can be broken into 2 edges of value 1. Since
        we only have edges of 1 and 2 in this case, we can proceed with this approach.
    */
    void addEdge(int u, int v, int wt) {
        if(u == v) return;   // optimizing

        if(wt == 2) {
            _adjList[u].push_back(u + _v);  // this is where we split the intermediate vertex
            _adjList[u + _v].push_back(v);
        } else {
            _adjList[u].push_back(v);
        }
    }

    void printadjList() {
        for(int cnt = 0; cnt < _adjList.size(); cnt++) {
            cout << "[" << cnt << "] : ";
            for(auto v : _adjList[cnt])
                cout << v << "  ";
        }
        cout << endl;
    }
};

int main() {
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 0, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 3, 2);

  
    int src = 0, dest = 3;
    int len = g.getShortestPath(src, dest);
    cout << "\nShortest Distance between " << src
         << " and " << dest << " is " << len
          << endl;
    return 0;
}