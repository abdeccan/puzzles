#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Employee {
    public:
    int id;
    int importance;
    vector<int> subordinates;

    Employee(int _id, int _importance, vector<int> _subs) : id(_id), importance(_importance), subordinates(_subs) {

    }
};

unordered_map<int, Employee *> empMap;
    
    int getEmpImp(int id) {
        int tmp = empMap[id]->importance;
        for(auto e_id : empMap[id]->subordinates)
            tmp += getEmpImp(e_id);
        
        return tmp;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        for(auto e : employees)
            empMap[e->id] = e;
        
        int tmp = empMap[id]->importance;
        
        for(auto e_id : empMap[id]->subordinates)
            tmp += getEmpImp(e_id);
        
        return tmp;
    }

int main() {
    cout << "Print employee org importance" << endl;
    vector<Employee *> emps;
    emps.push_back(new Employee(1, 2, {2, 3}));
    emps.push_back(new Employee(2, 4, {4, 5, 6}));
    emps.push_back(new Employee(3, 6, {}));
    emps.push_back(new Employee(4, 8, {}));
    emps.push_back(new Employee(5, 10, {}));
    emps.push_back(new Employee(6, 12, {}));
    int imp = getImportance(emps, 1);
    cout << "Importance of 1 = " << imp << endl;
    return 0;
}