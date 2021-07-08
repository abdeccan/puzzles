#include <iostream>
using namespace std;

int getLCSubstring(string s1, string s2, int l1, int l2) {

    // logic: the logic is almost similar to longest common subsequence except that in 
    // case we encounter a mismatch between the two strings at any index, we reset the 
    // T[i][j] value to 0 and start counting again.

    int T[l1 + 1][l2 + 1];
    // initialization: init the 1st row and 1st col - this is similar to base 
    // condition in recursive approach
    for(int i = 0; i < l1 + 1; i++) T[i][0] = 0;
    for(int j = 0; j < l2 + 1; j++) T[0][j] = 0;

    // one more gotcha for longest common substring - the substring could be found anywhere
    // and hence we need to track the max value of the T[i][j]
    int lcsMax = 0;

    // choice diagram
    for(int i = 1; i < l1 + 1; i++) {
        for(int j = 1; j < l2 + 1; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                T[i][j] = 1 + T[i - 1][j - 1];
                if(lcsMax < T[i][j]) lcsMax = T[i][j];
            } else {
                T[i][j] = 0;    // here is the difference from longest common subseq!
            }
        }
    }

    return lcsMax;
}

int main() {
    cout << "Longest common substring" << endl;
    string s1 = "abcde";
    string s2 = "abbcde";
    int lcSubstr = getLCSubstring(s1, s2, s1.size(), s2.size());
    cout << "lcSubstr = " << lcSubstr << endl;
    return 0;
}