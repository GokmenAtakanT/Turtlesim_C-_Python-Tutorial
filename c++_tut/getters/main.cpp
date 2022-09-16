#include <iostream>

using namespace std;
class movie{
private:
        string rating;

public:
    string name;
    string director;
    movie(string a_name,string a_director, string a_rating){
    name=a_name;
    director=a_director;
    setrating(a_rating);
    }
    void setrating(string a_rating){
        if(a_rating== "PG_13"|| a_rating =="PG" || a_rating == "PG18"){
            rating=a_rating;
        }
        else{

            rating="NR";
        }
    }
    string getrating(){
            return rating;

    }

};
int main()
{
    movie movie1("Avatar","James Cameron","PG_13");
    cout << movie1.getrating()<< endl;
    movie1.setrating("PG");
    cout << movie1.getrating() << endl;
    return 0;
}
