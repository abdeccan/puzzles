#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;


class LRUCache_Old {
    private:
    
     /*class myComp {
      public:
         bool operator() (const int &p1, const int &p2) {
            return _usageCnt[p1] > _usageCnt[p2];
        }
    };*/
        
    int _cap;
    unordered_map<int, int> _cache;
    unordered_map<int, int> _usageCnt;
    //priority_queue<int, vector<int>, myComp> _q;
    
public:

    void printUsageAndDataCache() {
        cout << "--Data Cache--" << endl;
        for(unordered_map<int, int>::const_iterator it = _cache.begin(); it != _cache.end(); it++)
            cout << "       Cache key: " << it->first << " val: " << it->second << endl;
        cout << "--Data Cache--" << endl;

        cout << "--Usage Cache--" << endl;
        for(unordered_map<int, int>::const_iterator it = _usageCnt.begin(); it != _usageCnt.end(); it++)
            cout << "       key: " << it->first << " usage: " << it->second << endl;
        cout << "--Usage Cache--" << endl;


    }
    
    LRUCache_Old(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
        if(_cache.find(key) != _cache.end()) {
            // before returning increase the access count
            if(_usageCnt.find(key) != _usageCnt.end())
                _usageCnt[key]++;
            else
                _usageCnt[key] = 1;

            cout << "   Getting value key = " << key << " value = " << _cache[key] << " usage cnt = " <<   _usageCnt[key] << endl;
            
           // _q.push(key);
            
            return _cache[key];
        }
        else
            return -1;
    }
    
    void put(int key, int value) {

        cout << "   Put key " << key << " value = " << value << endl;
        
        if(_cache.find(key) != _cache.end()) {
            // update operation
            _cache[key] = value;
            cout << "   Key exists, update operation" << endl;
            
        } else {
            // write operation
            if(_cache.size() >= _cap) {
                cout << "!!Cap reached, need to evict!!" << endl;
                // we need to evict LRU now
                /*int keyToPop = _q.top();
                _q.pop();
                _cache.erase(keyToPop);*/
                int minUsed = 2 * 1e5;
                int minKey = 1e4;
                for(unordered_map<int, int>::const_iterator it = _usageCnt.begin(); it != _usageCnt.end(); it++) {
                    if(minUsed > it->second) {
                        minUsed = it->second;
                        minKey = it->first;
                    }
                }
                cout << "   Evicting minKey = " << minKey << " minUse = " << minUsed << endl;
                _cache.erase(minKey);
                _cache[key] = value;
                _usageCnt.erase(minKey);
                
            } else {
                _cache[key] = value;
            }

            cout << endl;
        }

        if(_usageCnt.find(key) != _usageCnt.end())
                _usageCnt[key]++;
            else
                _usageCnt[key] = 1;
    }
};

class LRUCache {
    private:
        
    int _cap;
    int cnt = 0;
    unordered_map<int, list<pair<int,int>>::iterator> _cache;
    //unordered_map<int, int> _usageRecency;
    //priority_queue<int, vector<int>, myComp> _q;
    list<pair<int,int>> theList;
    
public:

   
    
    LRUCache(int capacity) {
        _cap = capacity;
    }
    
    void printlist(string m, list<int> l) {
        list<int>::iterator i = l.begin();
        cout << endl << m << "  ";
        while(i != l.end()) {
            cout << "  " << *i << "  ";
            i++;
        }        
    }
    
    int get(int key) {
        if(_cache.find(key) != _cache.end()) {
            // before returning increase the access count
        //    _usageRecency[key] = ++cnt;

        //    cout << "   Getting value key = " << key << " value = " << _cache[key] << " usage cnt = " <<   _usageRecency[key] << endl;
            
           // _q.push(key);
          /*  list<int>::iterator it = useList.begin();
            while(it != useList.end() && *it != key)
                it++;*/
           // printlist(string("get, before rearrange"), useList);
    //        useList.remove(key);
  //          useList.push_back(key);
            theList.splice(theList.begin(), theList, _cache[key]);
           // printlist(string("get, after rearrange"), useList);
                
            
            return _cache[key]->second;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {

     //   cout << "   Put key " << key << " value = " << value << endl;
        
        if(_cache.find(key) != _cache.end()) {
            // update operation
            _cache[key]->second = value;
      //      cout << "   Key exists, update operation" << endl;
            theList.splice(theList.begin(), theList, _cache[key]);
        } else {
            // write operation
            if(_cache.size() >= _cap) {
               // cout << endl << "!!Cap reached, need to evict!!" << endl;
              //  printlist(string("put, before evict"), useList);
                // we need to evict LRU now
                /*int keyToPop = _q.top();
                _q.pop();
                _cache.erase(keyToPop);*/
                
                //evict the least used
                pair<int, int> lastnode = theList.back();
                theList.pop_back();
                _cache.erase(lastnode.first);

                /*int minUsed = 2 * 1e5;
                int minKey = 1e4;
                for(unordered_map<int, int>::const_iterator it = _usageRecency.begin(); it != _usageRecency.end(); it++) {
                    if(minUsed > it->second) {
                        minUsed = it->second;
                        minKey = it->first;
                    }
                } */
           
               // int minKey = useList.front();
             //   cout << "   Evicting minKey = " << minKey << endl;
               // useList.pop_front();
               // printlist(string("put, after evict"), useList);
               // _cache.erase(minKey);
//                _usageRecency.erase(minKey);
                
            } else {
                _cache[key] = value;
            }
            
            theList.push_front({key, value});
                _cache[key] = theList.begin();

          //  cout << endl;
        }

     //   _usageRecency[key] = ++cnt;
    }
};

int main() {
    cout << "LRU cache eviction" << endl;
    
    LRUCache lRUCache(2);
    lRUCache.printUsageAndDataCache();
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.printUsageAndDataCache();
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.printUsageAndDataCache();
    lRUCache.get(1);    // return 1
    lRUCache.printUsageAndDataCache();
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.printUsageAndDataCache();
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.printUsageAndDataCache();
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.printUsageAndDataCache();
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.printUsageAndDataCache();
    lRUCache.get(3);    // return 3
    lRUCache.printUsageAndDataCache();
    lRUCache.get(4);    // return 4
    lRUCache.printUsageAndDataCache();

    return 0;
}