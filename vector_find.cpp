#include <iostream>
#include <vector>
using namespace std;

struct MyStruct {
    string name;
    int id;
};

int main() {
    vector<MyStruct> v;
    MyStruct s1, s2, s3;
    s1.name = "Jon";s1.id = 1;
    s2.name = "David";s2.id = 2;
    s3.name = "Mike";s3.id = 3;

    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);

    int id_to_find = 1;

    if( std::find(v.begin(), v.end(), [&id_to_find](const MyStruct &arg) { 
                                           return arg.id == id_to_find; }) == v.end())
        cout << "Not found";
    else
        cout << "Found";

    cout << endl;
    return 0;
}