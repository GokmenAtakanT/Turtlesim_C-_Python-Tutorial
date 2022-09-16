#include <iostream>

using namespace std;

int main()
{
    int age=19;
    double dage=19.5;
    string name;
    cout<< "enter name "<<endl;
    getline(cin,name);
    cout << "age " << *&age <<endl;
    cout << "dage " << &dage <<endl;
    cout << "name " << *&name <<endl;

    return 0;
}
