#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, int N, vector<string> board) {
    // logic: we only need to check three directions i.e.
    // 1. to the left
    // 2. upper left diagonal
    // 3. lower left daigonal
    // no need to check for upper rows in col since we would not place more than 1 queen in single col
    // no need to check right lower and right upper and right because we are filling queens from the left
    
    // 1. to the left
    int tmpCol = col;
    int tmpRow = row;
    while(col >= 0) {
        if(board[row][col] == 'Q')
            return false;

        col--;
    }

    col = tmpCol;
    row = tmpRow;
    // 2. upper left diagonal
    while(col >= 0 && row >= 0) {
        if(board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    col = tmpCol;
    row = tmpRow;
    // 3. lower left diagonal
    while(col >= 0 && row < N) {
        if(board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }

    return true;
}

void solve(int N, int col, vector<string> board, vector<vector<string>> &boards) {
    // base condition
    if(col == N) {
        // have we crossed the last col?
        boards.push_back(board);
        return;
    }

    // backtracking
    for(int row = 0; row < N; row++) {

        if(!isSafe(row, col, N, board)) continue;

        // progress
        board[row][col] = 'Q';
        // recurse
        solve(N, col + 1, board, boards);
        // backtrack
        board[row][col] = '.';
    }
}

int main() {
    cout << "N-queens problem" << endl;
    // req: find how many different ways N queens can be placed in a N * N chess board
    // such that each row has exactly one queen, each col has only one queen
    // no two queens can attack each other

    int N = 6;  // 4 * 4 chess board
    int startCol = 0;
    vector<string> board;   // one such board to start with
    for(int i = 0; i < N; i++) {
        string s(N, '.');
        board.push_back(s);
    }
        
    vector<vector<string>> boards;  // collection of all possible board positions
    solve(N, startCol, board, boards);
    for(auto b : boards){
        for(auto r : b)
            cout << r << "  " << endl;

        cout << endl;
    }
    cout << "Total number of ways = " << boards.size() << endl;
    cout << endl;
    return 0;
}