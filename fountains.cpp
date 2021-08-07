#include <iostream>
#include <vector>
using namespace std;

int getMinTaps(vector<int> &taps, int n) {
    int cnt = 0;

    // logic: we first calculate the jump/ range of each tap and store it
    // in the jump array - this is nothing but how far water can jump
    vector<int> jump(n+1, 0);
    
    for(int i = 0; i <= n; i++) {
        int l = max(0, i-taps[i]);
        int r = min(n, i + taps[i]);
        jump[l] = r;
    }
    int next = 0, curr = 0;
    for(int i = 0; i <= curr; i++) {
        next = max(next, jump[i]);
        
        if(i == curr) {
            curr = next;
            cnt++;
            if(curr >= n)
                return cnt;
        }
    }

    return -1;
}

int main() {
    cout << "Fountain problem" << endl;
    vector<int> taps = {1,2,1,0,2,1,0,1};
    int n = 7 ; // length of garden
    int tapCnt = getMinTaps(taps, n);
    cout << "Min taps = " << tapCnt << endl;
    return 0;
}