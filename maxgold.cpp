#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited) {
        int r = grid.size();
        int c = grid[0].size();
        
        if(i == c || i < 0 || j < 0 || j == c || visited[i][j] /*|| grid[i][j] == 0*/) return 0;
        
        // we can move 1 step right/ right diagonal up/ right diagonal down        
        //vector<pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}};
        vector<pair<int, int>> directions = {{0, 1}, {-1, 1}, {1, 1}};
        
        visited[i][j] = true;
        
        int gold = 0;
        int sum = grid[i][j];
        cout << sum << " --> [" << i << ", " << j << "] --> " << endl;
        for(pair<int, int> dir : directions) {
            gold = max(gold, dfs(grid, i + dir.first, j + dir.second, visited));
        }
        cout << gold + sum << endl;
        return gold + sum;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(r == 0 || c == 0) return 0;

        int maxG = 0;

        vector<vector<bool>> visited(r, vector<bool>(c));

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                // do DFS
                maxG = max(maxG, dfs(grid, i, j, visited));
            }
        }

        return maxG;
    }

    /*
        ALT solution without using DFS: https://www.geeksforgeeks.org/gold-mine-problem/
    */

    int main() {
        vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
        int maxG = getMaximumGold(grid);
        cout << maxG << endl;
        return 0;
    }