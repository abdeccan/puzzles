#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited) {
        int r = grid.size();
        int c = grid[0].size();
        
        if(i > r - 1 || i < 0 || j < 0 || j > c - 1 || visited[i][j] || grid[i][j] == 0) return 0;
        
        // we can move 1 step up/ down/ right/ left        
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        visited[i][j] = true;
        
        int gold = 0;
        int sum = grid[i][j];
        
        for(pair<int, int> dir : directions) {
            gold = max(gold, dfs(grid, i + dir.first, j + dir.second, visited));
        }
        
        return gold + sum;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(r == 0 && c == 0) return 0;
        
        vector<vector<bool>> visited(r, vector<bool>(c));
        
        int ans = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0;j < c; j++) {
                // we do DFS to gather all gold in connected paths
                ans = max(ans, dfs(grid, i, j, visited));
            }
        }
        
        return ans;
    }

    int main() {

        vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
        int maxG = getMaximumGold(grid);
        cout << maxG << endl;
        return 0;
    }