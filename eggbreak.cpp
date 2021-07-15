#include <iostream>
using namespace std;

int memo[101][101];

int getAttempts(int eggs, int floors) {
    // logic: we want to find the min number of attempts in the worst case e.g. eggs dont break
    // until top floor and we start at the ground floor.

    // base condition: if eggs == 0, we dont have anything to throw - numAtt = 0
    // if eggs == 1, numAtt = floors i.e. we have to keep trying from every floor
    // if floors = 0 or 1, numAtt = 0 or 1
    if(eggs == 0) return 0;

    if(eggs == 1) return floors;

    if(floors == 0 || floors == 1) return floors;

    if(memo[eggs][floors] != -1) return memo[eggs][floors];

    int mn = INT_MAX;

    // looping logic: here k can traverse from i to j, both values included
    for(int k = 1; k <= floors; k++) {
        // e-1, k-1 when egg breaks from kth floor, e, f-k when egg doesnt break
        // consider max of these two since we are finding worst case!
        int tmp = 1 + max(getAttempts(eggs - 1, k -1), getAttempts(eggs, floors - k));
        mn = min(mn, tmp);
    }

    memo[eggs][floors] = mn;

    return mn;
}

int main() {
    cout << "Egg dropping problem" << endl;
    int eggs = 2, floors = 4;
    memset(memo, -1, sizeof(memo));
    int numAtt = getAttempts(eggs, floors);
    cout << "Num attempts = " << numAtt << endl;
    return 0;
}