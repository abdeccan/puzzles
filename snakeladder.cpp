#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 29;

struct qentry {
    int index;
    int throws;
};

int getMinThrows(vector<int> board) {
    vector<bool> visited(30, false);

    queue<qentry> q;
    q.push({0, 0});
    visited[0] = true;
    int numThrows = 1;
    
    while(!q.empty()) {
        qentry front = q.front();
        if(front.index == N) {
            // game over!
            return front.throws;
        }

        q.pop();

        // traverse the adjacencies of this vertex
        for(int i = front.index + 1; i < front.index + 6 && i <= N; i++) {
            if(!visited[i]) {
                visited[i] = true;
                qentry tmp;
                tmp.throws = front.throws + 1;
                if(board[i] != -1) {
                    tmp.index = board[i];                    
                } else {
                    tmp.index = i;
                }
                q.push(tmp);
            }
        }
    }

    return 0;

}

int main() {
    cout << "Min num of dice throws to reach destination" << endl;

    // logic: consider the board as a vector of int indicating a jump vector. Where
    // a snake comes, the array value at that index indicates the tail of snake. Like
    // wise if a ladder comes, the array value at that index indicates the head of
    // the ladder. Rest of the cells are all -1 and have no special effect.
    // Each array index/ cell can be considered to be potentially connected to 6 other
    // cells since dice throw can be from 1-6. If the dice throw lands on a snake head,
    // we go down to the tail. Like wise for ladder.

    // Here we can think of this board as a graph where each edge can be thought of
    // as having same weight - here we are interested in the number of throws as
    // the edge weight and not the cell value.

    // So we can use BFS to identify the shortest possible path to the top.
    
    vector<int> board(30, -1);  // init the board with all default cells

    board[2] = 21;
    board[4] = 7;
    board[10] = 25;
    board[19] = 28;
    
    board[16] = 3;
    board[18] = 6;
    board[20] = 8;
    board[26] = 0;

    int minThrows = getMinThrows(board);

    cout << "Min throws is " << minThrows << endl;
    return 0;
}