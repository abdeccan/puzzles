#include <iostream>
#include <vector>
using namespace std;


 vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the array first
        sort(nums.begin(), nums.end());
        
        int size = nums.size();
        int lo = 1;
        int hi = size - 1;
        
        
        vector<vector<int>> res;
        int i = 0;
        while(i < size) {
            lo = i + 1;
            hi = size - 1;
            
            if(i > 0 && nums[i] == nums[i-1]) {
                ++i;
                continue;                
            }
            
            while(lo < hi) {
                int reqSum = nums[lo] + nums[hi];
                if(reqSum + nums[i] == 0)
                {
                    res.push_back({nums[i], nums[lo], nums[hi]});
                    lo++;
                    hi--;
                    while(lo < hi && nums[lo] == nums[lo - 1]) ++lo;
                }
                else if(reqSum + nums[i] < 0) 
                    lo++;
                else if(reqSum + nums[i] > 0)
                    hi--;
            }
            
            ++i;
        }
        
        return res;
    }

    int main() {
        cout << "Three sum problem" << endl;
        vector<int> input = {-1,0,1,2,-1,-4};// {0,0,0,0,0};//{-1,0,1,2,-1,-4};
        vector<vector<int> > output = threeSum(input);
        for(auto v : output) {
            cout << endl;
            for(auto i : v)
                cout << i << "  ";
        }
        cout << endl;
        return 0;
    }
