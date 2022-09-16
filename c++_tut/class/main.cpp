#include <iostream>

using namespace std;

class book{
public:
    string title;
    string name;
    int pages;
    book(string name){
    cout << name<< endl;
    }
};

int main()
{
    book book1("Lord of The Ring");
    book1.title="Lord of The Ring";
    book1.name="Tolkien";
    book1.pages=500;

    book book2("Harry Potter");
    book1.title="Harry Potter";
    book1.name="J k Rowling";
    book1.pages=700;
    cout << book1.name<< endl;
    return 0;
}
