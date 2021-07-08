#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T_Memo[101][101];

int getLCSLen(string s1, string s2, int l1, int l2) {
    // logic: there are 2 strings and we will start at the end of the string by comparing the
    // last characters of both the strings. 
    // If they are same, LCS ++ and then check for: 
    //      (s1-last char) and (s2- last char); 
    // else there are 2 options we have:
    //      check for (s1-last char, s2) and (s1, s2- last char)
    // this can be expressed neatly as a recursive code.

    int lcsLen = 0;

    // base condition for this recursive code
    if(l1 == 0 || l2 == 0) return 0;    // this means at least one string has become empty
    
    // choice diagram
    if(s1[l1 - 1] == s2[l2 - 1]) {
        lcsLen += 1 + getLCSLen(s1, s2, l1 - 1, l2 - 1);
    } else {
        lcsLen += max(getLCSLen(s1, s2, l1 - 1, l2), getLCSLen(s1, s2, l1, l2 - 1));
    }
    
    return lcsLen;
}

int getLCSLen_Memo(string s1, string s2, int l1, int l2) {
    // logic: enhance recursive code by memoizing previously computed values.

    int lcsLen = 0;

    // base condition for this recursive code
    if(l1 == 0 || l2 == 0) return 0;    // this means at least one string has become empty

    if(T_Memo[l1][l2] != -1) return T_Memo[l1][l2];
    
    // choice diagram
    if(s1[l1 - 1] == s2[l2 - 1]) {
         lcsLen = 1 + getLCSLen(s1, s2, l1 - 1, l2 - 1);
    } else {
        lcsLen = max(getLCSLen(s1, s2, l1 - 1, l2), getLCSLen(s1, s2, l1, l2 - 1));
    }
    
    T_Memo[l1][l2] = lcsLen;
    return lcsLen;
}

int getLCSLen_BottomUp(string s1, string s2, int l1, int l2) {
    // logic: here we store the values directly into the bottom up table
    // see knapsack for more context & details

    int T[l1 + 1][l2 + 1];

    // initialization: init the 1st row and 1st col - this is similar to base 
    // condition in recursive approach
    for(int i = 0; i < l1 + 1; i++) T[i][0] = 0;
    for(int j = 0; j < l2 + 1; j++) T[0][j] = 0;

    // choice diagram
    for(int i = 1; i < l1 + 1; i++) {
        for(int j = 1;j < l2 + 1; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                T[i][j] = 1 + T[i - 1][j - 1];
             } else {
                 T[i][j] = max(T[i - 1][j], T[i][j - 1]);
             }
        }
    }

    for(int i = 0; i < l1 + 1; i++) {
        cout << endl;
        for(int j = 0; j < l2 + 1; j++) {
            cout << "   " << T[i][j];
        }
    }

    // print the lcs string
    // logic: we start with T[l1][l2] and keep checking if the value s1[i - 1] == s2[j - 1]
    // if yes, we insert that character into a string. then move diagonally up to the left i.e.
    // from T(i, j) --> T(i - 1, j - 1)
    // else we check the max of this cell's neighbors (i, j - 1) and (i - 1, j) and move there
    // accordingly i.e.
    // from T(i, j) --> max(T(i - 1, j), T(i, j - 1))
    // repeat till we reach the first row/ col
    int i = l1, j = l2;
    string lcs;
    while(i > 0 && j > 0) {
        if(s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];
            i--;
            j--;
        } else if(T[i - 1][j] > T[i][j - 1]) {
                i--;
        } 
        else {
            j--;    
        }
    }

    reverse(lcs.begin(), lcs.end());
    cout << endl << "LCS = " << lcs << endl;

    string lcs2;
    for(int i = 1; i < l1 + 1; i++) {
        if(T[i][l2] > T[i - 1][l2]) {
            lcs2 += s1[i - 1];
        }
    }
    cout << " lcs2 " << lcs2 << endl;

    return T[l1][l2];
}

int main () {
    cout << "Find the length of the longest common subsequence between two strings" << endl;
    string s1 = "abcgabcd";
    string s2 = "axbyczdweu";
    
    int lcsLen = getLCSLen(s1, s2, s1.size(), s2.size());
    cout << "LCS len = " << lcsLen << endl;
    
    memset(T_Memo, -1, sizeof(T_Memo));
    lcsLen = getLCSLen_Memo(s1, s2, s1.size(), s2.size());
    cout << "LCS getLCSLen_Memo = " << lcsLen << endl;

    lcsLen = getLCSLen_BottomUp(s1, s2, s1.size(), s2.size());
    cout << "LCS getLCSLen_BottomUp = " << lcsLen << endl;

    return 0;
}