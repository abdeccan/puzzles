#include <iostream>
#include <string>
using namespace std;

void getMinInsertAndDelete(string s1, string s2, int l1, int l2) {
    // logic: the basic logic is that to convert s1 to s2, we first reduce i.e. delete chars from s1 
    // to the LCS between s1 and s2 and then insert chars to make it s2.
    // the minimum number of insert and deletes would then be the sum of the differences above.
    //
    // e.g. s1 = geek, s2 = eke
    // LCS = ek
    // step 1: reduce i.e. delete from s1 to LCS --> 2 deletes
    // step 2: build from LCS to s2 --> 1 insert
    // answer: 2 deletes and 1 insert

    // First we need to find the LCS len for s1 and s2
    int T[l1 + 1][l2 + 1];

    for(int i = 0; i < l1 + 1; i++) T[i][0] = 0;
    for(int j = 0; j < l2 + 1; j++) T[0][j] = 0;

    for(int i = 1;i < l1 + 1; i++) {
        for (int j = 1; j < l2 + 1; j++) {
            if( s1[i - 1] == s2[j - 1]) {
                T[i][j] = 1 + T[i - 1][j - 1];
            } else {
                T[i][j] = max(T[i - 1][j], T[i][j - 1]);
            }
        }
    }

    int lcs = T[l1][l2];
    int numDel = s1.size() - lcs;
    int numIns = s2.size() - lcs;
    cout << "Num deletes = " << numDel << " Num Inserts = " << numIns << endl;
}

int main() {
    cout << "Minimum number of insert and delete to change string s1 to string s2" << endl;
    string s1 = "pea"; //"geek";
    string s2 = "heap"; //"eke";
    getMinInsertAndDelete(s1, s2, s1.size(), s2.size());
    return 0;
}