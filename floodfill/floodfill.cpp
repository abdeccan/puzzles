#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        vector<vector<int> > resultMatrix = image;
        return resultMatrix;
    }
};

int main()
{
    vector<vector<int> > img;
    Solution mySol;
    mySol.floodFill(img, 1, 1, -1);
    return 0;
}