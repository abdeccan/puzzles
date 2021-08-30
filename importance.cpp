#include <iostream>
#include <map>
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

int getEmpImp(vector<Employee*> employees, map<int, vector<int>> subs, int id) {
    int tmp = subs[id];
    for(auto s : subs[id]) {
        tmp += getEmpImp(employees, subs, s);
    }
    return tmp;
}

int getImportance(vector<Employee*> employees, int id) {
    map<int, vector<int>> subs;
    for(auto e : employees)
        subs[e->id] = e->subordinates;
    
    return getEmpImp(employees, subs, id);
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