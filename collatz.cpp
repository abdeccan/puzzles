#include <iostream>
using namespace std;

void printCollatzStoppingTimes(unsigned int N) {
    if(N == 0) return;
    cout << "Collatz seq for " << N << ":";
    unsigned int MAX_TIMES = 1000;  // we dont want to go into an infinite loop
    int tmp = N;
    int i = 0;
    for(; i < MAX_TIMES; i++) {
        if(tmp == 1) break;
        if((tmp & 1) == 1) 
            tmp = 3*tmp + 1;
        else 
            tmp = tmp/2;
        cout << " " << tmp;
    }
    cout << " stopping point: " << i << endl;
}

int main() {
    cout << "Collatz conjecture - find stopping points for first N numbers" << endl;
    for(unsigned int i = 1; i < 20; i++)
        printCollatzStoppingTimes(i);
    cout << endl;
    return 0;
}