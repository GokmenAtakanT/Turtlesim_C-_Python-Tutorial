#include <iostream>

using namespace std;
string day(int num){
string dayname;

switch(num){
 case 0:
 dayname="Monday";
 break;
 case 1:
 dayname="Thuesday";
 break;
 case 2:
 dayname="Wednasday";
 break;
 default:
 dayname="other";


}
return dayname;

}

int main()
{
    bool male=true;
    bool tall=true;

    cout << "enter Size True or False " << endl;
    cin >> tall;

    cout << "enter gender True or False " << endl;
    cin >> male;



    if (male && tall)
    {
    cout << "Male tall"<<endl;
    }
    else if(male && !tall){
    cout << "Not tall male";
    }

    else if(!male && tall){
    cout << "tall female";
    }
    else {
    cout << "Not tall female";
    }

    string res=day(1);
    cout << res<<endl;
    return 0;
}
