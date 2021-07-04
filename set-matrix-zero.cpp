#include <iostream>
#include <vector>
using namespace std;

void setMatrixZero(vector<vector<int>> &mat){

}

int main() {
    cout << "Set matrix zeros" << endl;
    vector<vector<int>> mat = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    for(auto r : mat) {
        cout << endl;
        for(auto c : r)
            cout << c << "  ";
    }
    cout << endl;
    return 0;
}