#include <iostream>
using namespace std;

bool inline isLeapYr(int y) {
        if(y % 400 == 0) return true;
        if(y % 100 == 0) return false;
        if(y % 4 == 0) return true;
        return false;
    }
    
    int daysInMth (int yr, int mth)
    {
        int days[12] = {31, isLeapYr(yr) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return days[mth-1];
    }
    
    int noOfDays(int D1, int M1, int Y1, int D2, int M2, int Y2) {
        
        int y1 = 0, y2 = 0, m1 = 0, m2 = 0, d1 = 0, d2 = 0;
        
        if(Y1 < Y2 || (Y1 == Y2 && M1 < M2) || (Y1 == Y2 && M1 == M2 && D1 <= D2)) {
            y1 = Y1;
            m1 = M1;
            d1 = D1;
            y2 = Y2;
            m2 = M2;
            d2 = D2;
        } else {
            y1 = Y2;
            m1 = M2;
            d1 = D2;
            y2 = Y1;
            m2 = M1;
            d2 = D1;
        }
  
        int numDays = 0;
        
        // date1 to its month end
        numDays += daysInMth(y1, m1) - d1;

        if(m1 == m2 && y1 == y2) return numDays - (daysInMth(y1, m1) -d2);
        
        // date1 till its year end
        int tmpMth = y2 == y1 ? m2 : 12;
        for(int i = m1+1; i <= tmpMth; i++)
        {
            numDays += daysInMth(y1, i);
            if(y1 == y2 && i == tmpMth) {
                // we have added till m2 end which we may need to offset
                numDays = numDays - (daysInMth(y1, i) - d2);
                return numDays;
            }
        }
        
        // get till the year end before this year
        for(int i = y1 + 1; i < y2; i++) {
            if(isLeapYr(i)) numDays += 366;
            else numDays += 365;
        }
        
        // add start of year till d2
        for(int i = 1; i < m2; i++) {
            numDays += daysInMth(y2, i);
        }
        
        // finally add the days in m2
        numDays += d2;
        
        return numDays;
    }

    int main() {
        cout << "Difference between dates is " << noOfDays(1, 3, 2000, 1, 2, 2000) << endl;
        return 0;
    }