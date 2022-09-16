#include <iostream>

using namespace std;

class abstractbook{
    virtual void goodbook()=0;
};

class book:abstractbook {
private:
string Title;
string aName;
int Pages;
public:

    book(){
        Title="No title";
        aName="no author";
        Pages=0;
        cout << aName<< endl;
    }
    book(string atitle,string aname, int apages){

        setbooktitle(atitle);
        setbookaName(aname);
        setbookpages(apages);
        cout << aName<< endl;

    }
    void setbooktitle(string atitle){
        Title=atitle;
    }
        void setbookaName(string aname){
        aName=aname;
    }
        void setbookpages(int apages){
        Pages=apages;
    }

        string getbooktitle(){
        return Title;
        }
        string getbookaName(){
        return aName;
        }
        int getbookpages(){
        return Pages;
        }
        void goodbook(){
            if (Pages>100){
                cout << Title<< "book is great "<<endl;
            }
            else{
                cout << Title << "book is bad" <<endl;
            }
        }


    //cout << aName<< endl;

};

class student{
public:
    string sname;
    string job;
    double grade;
    student(string a_name){
    sname=a_name;
    job="No Job";
    grade=0.0;
    cout << sname << " " << job << " " << grade << endl;

    }
    student(string a_name,string a_job, double a_grade){
    sname=a_name;
    job=a_job;
    grade=a_grade;
    cout << sname << " " << job << " " << grade << endl;

    }

    bool honor(){
    if(grade>3.5){
        return true;
    }
        return false;
    }

};

int main()
{
    book book1("Lord of The Ring","Tolkien",500);
    book book2("Harry Potter","J k Rowling",700);
    book book3;
    cout << book1.getbooktitle()<< endl;

    book1.goodbook();

    student student1("John","Engineer",3.41);
    student student2("Jack","Doctor",3.6);
    student student3("Mark");

    cout << student2.honor()<< endl;

    return 0;
}
