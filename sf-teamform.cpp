// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


inline int getFact(int m, int n) {
    /*
        this will tell us the val of m!/(n! * (m-n)!), m >= n        
    */
    
    cout <<" getFact " << m << " " << n << endl;
    if(m <= n) return 1;
    
    return m * (m - n)/ (n);
}


/*
 * Complete the 'countTeams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY skills
 *  2. INTEGER minPlayers
 *  3. INTEGER minLevel
 *  4. INTEGER maxLevel
 */

int countTeams(vector<int> skills, int minPlayers, int minLevel, int maxLevel) {
    /*
        DRAFT approach:
        1. filter out players outside the skill level i.e. < minSkill && > maxSkill
        2. this will give us available pool of players to choose from
        3. if avbl pool smaller than minPlayers, bail out
        4. total num of ways = factorial(pool.size())/ (factorial(minPlayer) * factorial(avblPool - minPlayer)) + factorial(pool.size())/ factorial(minPlayer + 1) .. 
        5. until minPlayer + m == pool.size
            4!/3! + 4!/4! = 5
            
            from 4 ppl, i have to choose teams with atleast 2 pl
            
            4!/(2! * 2!) + 4!/(3! * 1!) + 4!/4! * 0! = 6 + 4 + 1 = 1
            
    */
    
    if(minPlayers < 1 || minLevel < 1 || maxLevel > 1000) {
        return 0;   // doesnt make sense to form teams
    }
    
  //  cout << " minskill " << minLevel << " maxLevel = " << maxLevel << " minPl = " << minPlayers << endl;
    for (auto p : skills) 
       cout << p << "  ";
    
    
    // filter out the ineligible players based on skill level
    vector<int> avblPool;
    for(auto p : skills) {
        if(p >= minLevel && p <= maxLevel)
            avblPool.push_back(p);
    }
    
    cout << "avblPool : " << avblPool.size() << endl;
    
    if((int)avblPool.size() < minPlayers)
    {
        return 0;
    }
    
    /*
    int numWays = fact(pool.size())/fact(minPlayers) + fact(pool.size())/fact(minPlayers + 1) ... + fact(pool.size())/fact(pool.size()); */
    
    int numWays = 0;
    int cnt = 0;
    while(minPlayers + cnt <= (int)avblPool.size()) {
        numWays = numWays + getFact(avblPool.size(), minPlayers + cnt++);
    }
   // cout << "numWays: " << numWays << endl;
    return numWays;
}



int main() {
    int n = 19;
    int r = 3;
    int prod = n;

    for(int i = 1; i < r; i++) {
        prod = prod * (n-i)/i;
    }

    prod = prod/r;
    cout << prod << endl;

    return 0;
}