#include <iostream>
using namespace std;

int count(string s, int i, int j, bool isTrue) {
    // logic: break the expression into right & left expressions. i can 
    // start at 0 and j can start at size - 1. 
    
    // base condition:
    if(i > j) return 0; // zero size expression!

    if(i == j) {
        // single char expression
        if(isTrue)
            return s[i] == 't' ? 1 : 0;
        else
            return s[i] == 'f' ? 1 : 0;
    }

    int ans = 0;

    // loop: k MUST always point to an operator - hence k
    // can start at i + 1 and MUST move by 2 always!
    for (int k = i + 1; k <= j - 1; k += 2) {
        int lt = count(s, i, k - 1, true);
        int lf = count(s, i, k - 1, false);
        int rt = count(s, k + 1, j, true);
        int rf = count(s, k + 1, j, false);

        if(s[k] == '^') {
            if(isTrue) {
                ans = ans + lt * rf + rt * lf;
            } else {
                ans = ans + lt * rt + lf * rf;
            }
        } else if (s[k] == '&') {
            if(isTrue) {
                ans = ans + lt * rt;
            } else {
                ans = ans + lt * rf + lf * rt + lf * rf;
            }
        } else if (s[k] == '|') {
            if(isTrue) {
                ans = ans + lt * rt + lt * rf + lf * rt;
            } else {
                ans = ans + lf * rf;
            }
        }
    }

    return ans;
}

int main () {
    cout << "Boolean expresssion evaluator" << endl;
    string s = "t^f&t";//"t^f&f|t";
    int numWays = count(s, 0, s.size() - 1, true);
    assert(numWays < 2);

    s = "t^f&f|t";
    numWays = count(s, 0, s.size() - 1, true);
    assert(numWays < 4);

    cout << "Num ways = " << numWays << endl; 
    return 0;
}