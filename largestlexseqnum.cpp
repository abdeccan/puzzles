#include <iostream>
#include <vector>
using namespace std;

bool backTrack(vector<int> &ans, int i, vector<bool> &seen) {

    int n = (ans.size() + 1)/2;

    if(i == ans.size()) return true;    // base condition

    // recursion
    if(ans[i] != 0) return backTrack(ans, i + 1, seen);

    // we do n..1 because we want to try out the largest num first in the empty slot
    // and if it doesnt fit, we move to next largest and all the way down to 1
    // which is the least value
    for(int j = n; j > 0; j--) {
        if(j == 1) {
            // process only if we havent seen this cell yet
            if(!seen[j]){
                // for j = 1 we need special handling because we have to fill only
                // one slot
                ans[i] = 1;     // make choice
                seen[j] = true;

                if(backTrack(ans, i + 1, seen)) // backtrack
                    return true;
                
                ans[i] = 0;     // undo choice
                seen[j] = false;
            }
        } else {
            // for other vals
            if(!seen[j] && (i + j < ans.size()) && ans[i + j] == 0) {
                ans[i] = ans[i + j] = j;    // make choice
                seen[j] = true;

                if(backTrack(ans, i + 1, seen))     // backtrack
                    return true;

                ans[i] = ans[i + j] = 0;    // undo choice
                seen[j] = false;
            }
        }
    }

    return false;
}

int main() {
    cout << "Print the largest lexicographically valid sequence" << endl;
    int n = 5;  // 1 occurs once, 2..5 occurs twice, distance between first occurrence and next is that val
    int a = 5, b = 4 , c = 3, d = 2, e =1;
    bool great = a > b > c > d > e;

    vector<int> ans(2 * n - 1, 0);  // 2 * n - 1 because of above reason
    vector<bool> seen (2 * n - 1, false);
    
    backTrack(ans, 0, seen);

    for(auto v : ans)
        cout << v << "  ";
    
    cout << endl;

    return 0;
}