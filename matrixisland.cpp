#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

    inline bool isInside (int row, int col, int height, int width) {
        return (row >= 0 && row < height) && (col >=0 && col < width);
    }
    
    inline void checkNeighborFn (int row, int col, vector<vector<int>>& grid, vector<vector<bool>> &visited, queue<pair<int, int>> &q) {
        if(isInside(row, col, grid.size(), grid[0].size()) && !visited[row][col] && (grid[row][col] == 1)) {
            q.push({row, col});
            visited[row][col] = true;
        }
    }
    
    //Function to find unit area of the largest region of 1s.
    int findNumIslands(vector<vector<int>>& grid) {
        // Code here
        if(grid.empty() || grid[0].empty()) return 0;
        
        int answer = 0;
        const int height = grid.size();
        const int width = grid[0].size();
        
        vector<vector<bool>> visited(height, vector<bool>(width));
        for(int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                // we need to visit each and every node and its neighbors
                // if they are not visited, mark as visited and add to the back
                // of queue
                if(!visited[row][col] && grid[row][col] == 1) {
                    answer++;
                    
                    // we need to start BFS now by adding nodes to queue
                    // here the queue will contain the row, col pairs
                    queue<pair<int, int>> q;
                    visited[row][col] = true;
                    q.push({row, col});
                    auto checkNeighbor = [](int newrow, int newcol, vector<vector<int>>& grid, vector<vector<bool>> &visited, queue<pair<int, int>> &q) {
                        if(isInside(newrow, newcol, grid.size(), grid[0].size()) && !visited[newrow][newcol] && (grid[newrow][newcol] == 1)) {
                            q.push({newrow, newcol});
                            visited[newrow][newcol] = true;
                        }
                    };

                    while(!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        // we need to check the neighbors of 'p' object
                      
                        checkNeighbor(p.first + 1, p.second, grid, visited, q);
                        checkNeighbor(p.first - 1, p.second, grid, visited, q);
                        checkNeighbor(p.first, p.second + 1, grid, visited, q);
                        checkNeighbor(p.first, p.second - 1, grid, visited, q);
                        
                        checkNeighbor(p.first + 1, p.second + 1, grid, visited, q);
                        checkNeighbor(p.first + 1, p.second - 1, grid, visited, q);
                        checkNeighbor(p.first - 1, p.second + 1, grid, visited, q);
                        checkNeighbor(p.first - 1, p.second - 1, grid, visited, q);

                        
                    }
                }
                
            }
        }
        
        return answer;
    }

    int findMaxArea(vector<vector<int>> &grid) {
        int maxArea = 0;
        const int H = grid.size();
        const int W = grid[0].size();

        if(H == 0 || W == 0) return 0;
        

        // we need to store if a cell is visited or not in a matrix
        vector<vector<bool>> visited (H, vector<bool>(W));
       
        // iterate through the cells and then their 8 neighbors
        for(int r = 0; r < H; r++) {
            for(int c = 0; c < W; c++) {
                // check if a cell is NOT visited but is land (1)
                if(!visited[r][c] && grid[r][c] == 1) {
                    // count up
                    int tmpAns = 0;
                    
                    // look out for the neighbors in DFS fashion!
                    // we will use a stack to store these neighboring cells!
                    stack<pair<int, int>> st;
                    st.push({r, c});
                    visited[r][c] = true;

                    while(!st.empty()) {
                        pair<int, int> p = st.top();
                        st.pop();
                        ++tmpAns;

                        auto checkNeighbor = [](int newrow, int newcol, vector<vector<int>>& grid, vector<vector<bool>> &visited, stack<pair<int, int>> &q) {
                            if(isInside(newrow, newcol, grid.size(), grid[0].size()) && !visited[newrow][newcol] && (grid[newrow][newcol] == 1)) {
                                q.push({newrow, newcol});
                                visited[newrow][newcol] = true;
                            }
                        };

                        // we have 8 neighboring cells
                        checkNeighbor(p.first + 1, p.second, grid, visited, st);
                        checkNeighbor(p.first - 1, p.second, grid, visited, st);
                        checkNeighbor(p.first, p.second + 1, grid, visited, st);
                        checkNeighbor(p.first, p.second - 1, grid, visited, st);
                        
                       /* checkNeighbor(p.first + 1, p.second + 1, grid, visited, st);
                        checkNeighbor(p.first + 1, p.second - 1, grid, visited, st);
                        checkNeighbor(p.first - 1, p.second + 1, grid, visited, st);
                        checkNeighbor(p.first - 1, p.second - 1, grid, visited, st);*/
                    }

                    maxArea = max(maxArea, tmpAns);
                }
            }
        }

        return maxArea;
    }

int main() {
    cout << "Find the number of islands in a matrix" << endl;
    vector<vector<int>> grid = {    { 0, 0, 1, 1, 0 }, 
                                    { 1, 0, 1, 1, 0 }, 
                                    { 0, 0, 0, 0, 0 }, 
                                    { 0, 0, 0, 0, 1 } };
    int numIslands = findNumIslands(grid);
    cout << "Number of islands = " << numIslands << endl;

    int maxArea = findMaxArea(grid);
    cout << "Max area = " << maxArea << endl;
    return 0;
}