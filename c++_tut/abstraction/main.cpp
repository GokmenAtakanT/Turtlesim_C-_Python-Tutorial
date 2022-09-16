#include <iostream>

using namespace std;

class Employee{
protected:
string Name;
string Job;
int Age;
public:

    Employee(string name, string job, int age){
    getname(name);
    getjob(job);
    getage(age);
    cout<< Name << " Work as "<< Job << " and "<< Age << " years old"<<endl;

    }
    void getname(string name){
    Name=name;
    }
    string setname(){
    return Name;
    }
    void getjob(string job){
    Job=job;
    }
    string setjob(){
    return Job;
    }
    void getage(int age){
    Age=age;
    }
    int setage(){
    return Age;
    }


};

class Developer: public Employee{
public:
    string Program;
    Developer(string name, string job, int age,string program):Employee(name, job, age){

    Program=program;
    }
    void Fixbug(){
    cout << Name << " Fixed the bug Using "<< Program <<endl;
    }

};

int main()
{
    Employee Employee1("Ali", "Engineer",50);
    cout << Employee1.setname()<< endl;

    Developer d=Developer("Mehmet", "Engineer",50,"C++");
    d.Fixbug();
    cout<<d.setname()<<endl;
    cout<<d.setage()<<endl;

    return 0;
}
