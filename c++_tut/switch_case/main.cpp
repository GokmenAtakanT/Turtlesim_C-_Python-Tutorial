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
    cout << "Hello world!" << endl;
    int day_num;
    cin >> day_num;
    string res=day(day_num);
    cout << res<<endl;
    int guess;
    int target=10;

    while (guess != target){
    cout << "enter number"<<endl;
    cin >> guess;
    }
    cout <<"correct guess"<<endl;
    return 0;
}
