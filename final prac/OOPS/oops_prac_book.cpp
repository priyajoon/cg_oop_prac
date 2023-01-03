#include <bits/stdc++.h>
using namespace std;
class publication{
    protected:
    string title;
    float price;
    public:
    void get_data();
    void put_data();
    publication(){
        title=" ";
        price=0;
    }
};
class book : public publication{
    private:
    int pagecount;
    public:
    void get_book_data();
    void put_book_data();
    book(){
        pagecount=0;
    }
};

class tape : public publication{
    private:
    float playtime;
    public:
    void get_tape_data();
    void put_tape_data();
    tape(){
        playtime=0;
    }
};

void book :: get_book_data(){
    cout << "enter the title of the book: ";
    try{
        getline(cin>>ws,title);
        cout << endl;
        cout << "enter the price of the book: ";
        cin >> price;
        cout << "Enter the no of pages in the book: ";
        cin >> pagecount;
        if(price<0){
            throw(2);
        }
        
    }
    catch(int x){
        cout << "Price is not valid";
        price=0;
        pagecount=0;
        title=" ";
    }
}

void book:: put_book_data(){
    cout << "The title of the book: " << title << endl;
    cout << "The price of the book: " << price << endl;
    cout << "The no of pages are: " << pagecount << endl;
}
void tape:: get_tape_data(){
    cout << "Enter the title of the tape: " ;
    try{
       getline(cin >> ws,title);
       cout << "Enter the playtime of the tape: ";
       cin >> playtime;
       cout << "Enter the price of the tape: ";
       cin >> price;
       if(price<0){
           throw(2);
       }
    }
    catch(int x){
        playtime=0;
        title=" ";
        price=0;
    }

}

void tape:: put_tape_data(){
    cout << "The title of tape is: " << title << endl;
    cout << "The price of tape is: " << price << endl;
    cout << "teh playtime of tape is: " << playtime << endl;

}
int main (){
    publication p;
    book b;
    tape t;
    b.get_book_data();
    b.put_book_data();
    t.get_tape_data();
    t.put_tape_data();
    return 0;
}