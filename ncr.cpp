#include <iostream>
using namespace std;

int getNCR(int n, int r) {
    int p = 1;
    
    if(n == 0 || r == 0) return n;

    if(n < r) return n;

    for(int i = 0; i < r; i++)
        p = p * (n - i)/(i + 1);

    return p;
}

int main() {
    cout << "Program to print nCr value for n and r, Enter n followed by r:" << endl;
    int n = 0, r = 0;
    cin >> n ;
    cin >> r;

    int ncr = getNCR(n, r);
    cout << n << "C" << r << " = " << ncr << endl;
    return 0;
}