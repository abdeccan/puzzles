#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
        const int size = height.size();
        if(size == 0) return 0;
        // find maxL, maxR
        
        // maxL
       // vector<int> maxL(size), maxR(size);
        int *maxL = new int[size]; 
        int *maxR = new int[size];
        int tmpMax = height[0];
        for(int i = 0; i < size; i++) {
            tmpMax = max(tmpMax, height[i]); 
            maxL[i] = tmpMax;
        }
        
        // maxR
        tmpMax = height[size - 1];
        for(int i = size - 1; i >= 0 ; i--) {
            tmpMax = max(tmpMax, height[i]); 
            maxR[i] = tmpMax;
        }
        
        
        // for the result we need to find min(maxL, maxR) and then difference between height[i] 
        int sum = 0;
        for(int i = 0; i < size; i++) {
            sum += min(maxL[i], maxR[i]) - height[i];
        }
        delete[] maxR;
        delete[] maxL;
        return sum;
    }

    int main() {
        vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
        cout << trap(height) << endl;
        return 0;
    }