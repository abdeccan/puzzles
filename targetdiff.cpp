#include <iostream>
using namespace std;

int main() {
    cout << "Count the number of subset with a given difference" << endl;

    // logic here: lets split the array into two parts, each having sum S1 and S2. 
    // we know that S1 + S2 = S where S is the sum of all elem of array.
    // problem statement gives a diff 'd' between these sums i.e. S1 - S2 = d
    // from these two equations, solve for S1.
    // then use the countofsubsets problem to find number of subsets with sum S1.
}