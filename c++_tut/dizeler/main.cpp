#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    string character;
    double number=10.2;
    int age;
    cout << "enter " << "character" <<" name"<< endl;
    getline(cin,character);
    cout << "enter " << character <<" age"<< endl;
    cin >> age;
    number++;
    cout << "Hello " << character <<" to day is "<< number<<" day of the month "<< "you are"<<age<<"year old"<< endl;
    cout << character.length()*number << " "<<character[0] <<" "<<character.find("Long",0)<<" "<<character.substr(character.find("Long",0),4)<<endl;
    cout <<pow(number/2,number/9)<<endl;
    cout <<sqrt(number/2)<<endl;
    cout <<round(number/2)<<endl;
    cout <<ceil(number/2)<<endl;
    cout <<floor(number/2)<<endl;
    cout << fmax(3,10)<<endl;
    cout << fmin(3,10)<<endl;


    return 0;
}
