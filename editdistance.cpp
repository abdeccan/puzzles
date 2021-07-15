#include <iostream>
using namespace std;

int  getDistance(string s1, string s2, int size1, int size2) {
    // logic: only three operations are allowed - insert, replace and delete. with
    // these we need to find the min number of operations needed to transform s1 to s2
    
    // base condition: if both strings are empty return 0
    if(size1 == 0 && size2 == 0) return 0;

    int T[size1 + 1][size2 + 1];
    
    // initialization
    for(int j = 0; j < size2 + 1; j++) T[0][j] = j;
    for(int i = 0; i < size1 + 1; i++) T[i][0] = i;

    // loop
    for(int i = 1; i < size1 + 1; i++) {
        for(int j = 1;j < size2 + 1; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                T[i][j] = T[i - 1][j - 1];
            } else {
                T[i][j] = 1 + min(T[i - 1][j - 1], min(T[i][j - 1], T[i - 1][j]));
            }
        }
    }

    for(int i = 0; i < size1 + 1; i++) {
        cout << endl;
        for(int j = 0; j < size2 + 1; j++) {
            cout << T[i][j] << "    ";
        }
    }

    return T[size1][size2];
}

int main () {
    cout << "Edit distance between two strings" << endl;
    string s1 = "computer";// "saturday";
    string s2 = "commuter"; //"sunday";
    int editDist = getDistance(s1, s2, s1.size(), s2.size());
    cout << endl << "Edit dist = " << editDist << endl;
    return 0;
}