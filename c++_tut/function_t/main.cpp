#include <iostream>

using namespace std;

double nums(string name, int age){
    cout << "You are " << name << " and you are " << age <<" years old "<< endl;
    double result= age*age*age;
    return result;
}

int main()
{
    string character;
    int number=10;
    int age;
    cout << "enter " << "character" <<" name"<< endl;
    getline(cin,character);
    cout << "enter " << character <<" age"<< endl;
    cin >> age;
    cout << "Hello world!" << endl;
    double result=nums(character,age);
    cout << "Result = "<< result << endl;

    return 0;
}
