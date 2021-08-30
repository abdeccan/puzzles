#include <iostream>
#include <list>
using namespace std;

int main() {
    auto print = [](list<int> l) {
        auto it = l.begin();
        cout << "Printing l: ";
        while(it != l.end())
            cout << *it++ << "    ";

        cout << endl;
    };

    list<int> l = {1, 2, 3, 4};
    list<int> l2 = {10, 20, 30, 40};
    list<int>::iterator it = l.begin();
    print(l);
    advance(it, 2);
    l.splice(l.begin(), l, it); 
    print(l);

    return 0;

}