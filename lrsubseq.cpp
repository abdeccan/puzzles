#include <iostream>
using namespace std;

int getLRS(string s1, string s2, int l1, int l2) {
    // logic: same as LCS problem, just that we compare the string 's' with
    // itself and do not count the char similarity if the index is same. this 
    // is because the char needs to be at different positions for the subseq
    // to repeat i.e. the char has to repeat and not be at same pos.
    // see lcsubseq for more context & details

    int T[l1 + 1][l2 + 1];

    // initialization: init the 1st row and 1st col - this is similar to base 
    // condition in recursive approach
    for(int i = 0; i < l1 + 1; i++) T[i][0] = 0;
    for(int j = 0; j < l2 + 1; j++) T[0][j] = 0;

    // choice diagram
    for(int i = 1; i < l1 + 1; i++) {
        for(int j = 1;j < l2 + 1; j++) {
            if(s1[i - 1] == s2[j - 1] && 
            (i != j)    // this is the difference between lcsubseq and this!!
            ) {
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
    cout << "Find the length of the longest repeating subsequence in a given string" << endl;
    string s = "aabebcdd";
    string s2 = s;
    
    int lrsLen = getLRS(s, s2, s.size(), s2.size());
    cout << "LRS = " << lrsLen << endl;

    return 0;
}