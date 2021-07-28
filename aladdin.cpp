#include <iostream>
using namespace std;

int getStart(int magic[], int dist[], int size, int &bal) {
    int start = -1;

    // since its a circular route, break it down into two parts i --> N and 0 --> i where
    // i is the index from where the circular route might be possible.

    // step 1: find the first index from which circ might be possible
    for(int i = 0; i < size; i++){
        if(magic[i] >= dist[i]) {
            start = i;
            break;
        }
    }

    // the current value of i will be our starting point
    // iterate from i = start to i = size
    for(int i = start; i < size;) {
        bal += magic[i] - dist[i];
        i++;
        if(bal < 0) {
            
            // this starting point didnt work out, we need to search for next
            for(;i < size; i++) {
                if(magic[i] - dist[i] >= 0) {
                    bal = 0;
                    start = i;
                    break;
                }
            }
        } /*else {
            i++;
        }*/
    }

    // iterate from i = 0 to i = start - 1
    for(int j = 0; j < start; j++) {
        bal += magic[j] - dist[j];

        if(bal < 0) {
            return -1;
        }

    }

    return start;
}


int main() {
    cout << "Aladdin and magic carpets" << endl;
    int magic[] = {4, 6, 7, 4};// {3, 2, 5, 4};
    int dist[] = {6, 5 ,3 ,5};    //{2, 3, 4, 2};
    int size = sizeof(magic)/ sizeof(int);
    int bal = -1;
    int start = getStart(magic, dist, size, bal);

    cout << "Start = " << start << " and balance = " << bal << endl;

    return 0;    
}   