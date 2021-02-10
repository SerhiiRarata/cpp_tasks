#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Peson{
    string name;
    string surname;
    int age;    
};

int main(){
    vector<Peson> staff;
    staff.push_back({"Ivan", "Ivanov", 25});
    staff.push_back({"Petr", "Petrovov", 35});

    cout << staff[0].age << endl;

    return 0;
}