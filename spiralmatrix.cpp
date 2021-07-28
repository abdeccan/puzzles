#include <iostream>
#include <vector>
using namespace std;

void spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    //vector<int> result(r*c);
    for(int k = 0; k < ceil(r/2); k++) {
        for(int i = 0 + k, j = 0 + k; j < c-1-k; j++)
            cout << matrix[i][j] << " ";
        for(int j = c - 1 - k,  i = 0 + k; i < r-1-k; i++)
            cout << matrix[i][j] << " ";
        for(int i = r-1-k,  j = c-1-k; j >= 0 + k; j--)
            cout << matrix[i][j] << " ";
        for(int j = 0 + k,  i = r - 2 - k; i >= 1 + k; i--)
            cout << matrix[i][j] << " ";
    }

    cout << endl;
}

int main() {

    cout << "Spirally traverse the matrix" << endl;
    vector<vector<int>> matrix = {{1,2,3,4,5}, {5,6,7,8,6}, {9,10,11,12,7},{1,2,3,4,8},{1,2,2,3,4}};
    spirallyTraverse(matrix, matrix.size(), matrix[0].size());
    return 0;

}