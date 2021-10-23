#include <iostream>
using namespace std;

int main() {
    int prev = 0, curr = 1, tmp = 0;
    int N = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        tmp = curr;
        curr = curr + prev;
        prev = tmp;
        cout << "fib[i] = " << curr << endl;
    }
    
    
}