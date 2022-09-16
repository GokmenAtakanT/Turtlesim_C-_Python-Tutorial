#include <iostream>

using namespace std;

class chef{
public:

    void chicken(){
    cout << "Chef Making Chicken"<<endl;
    }

    void meat(){
    cout << "Chef Making meat"<<endl;
    }

    void salad(){
    cout << "Chef Making salad"<<endl;
    }
    void special(){
    cout << "Chef Making squid"<<endl;
    }

};

class italianchef : public chef{
public:
    void pasta(){
    cout<< "Chef Making Pasta"<<endl;
    }
    void special(){
    cout << "Chef Making sushi"<<endl;
    }

};
int main()
{
    chef chef1;
    italianchef italian1;
    chef1.special();
    italian1.special();
    //cout << "Hello world!" << endl;
    return 0;
}
