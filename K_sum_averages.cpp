#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<double> getAverages(int K, vector<int> inArray) {
    vector<double> averages;
    /*
        We are going to apply the sliding window technique on this array! Window size = K

        {1, 3, 2, 6, -1, 4, 1, 8, 2}

    */
   int cnt = 0, sum = 0, windowEnd = K-1;
   for(int index = 0; windowEnd < inArray.size(); index++) {
       sum += inArray[index];
       if(++cnt == K) {
           averages.push_back(((double)sum)/K);
           sum -= inArray[index+1-K];
           cnt--;
           windowEnd++;
       }
   }

    return averages;
}

int main (int argc, char **argv) {

    int K = 5;
    vector<int> inArray = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    vector<double> averages = getAverages(K, inArray); 
    for(auto e : averages) cout << e << endl;
    return 0;
}