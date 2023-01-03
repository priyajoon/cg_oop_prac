#include<bits/stdc++.h>
using namespace std;

int n;
const int N=10;
class publication
{
   protected:
   string title;
   float price;
   public:

   publication(){
      title="";
      price=0.0;
   }
   publication(string x,float x1){
      title=x;
      price=x1;
   }
   void getdata();
   void putdata();

   
   
};

class book: public publication
{
   int pagecount;
   public:
   void getdatab();
   void putdatab();

   book(){
      pagecount=0;
   }
};

class tape: public publication
{
   int playtime;
   public:
   void getdatat();
   void putdatat();

   tape(){
       playtime=0;
   }
};

void book::getdatab()
{
   cout<<"enter book title : ";
   getline(cin>>ws,title);
   cout<<"enter book price : ";
   cin>>price;
   cout<<"enter book pagecount : ";
   cin>>pagecount;

   //cin>>price;
   //cin>>pagecount;
    
   try{
      
      if(price<=0 || pagecount<=10)
	{
		throw (2);           
      	}
   }
   catch( int x)
   {
    cout<<"book price cannot be zero or pagecount cannot be less than 10"<<endl;	
	price=0;
	pagecount=0;
	
   }

}
void tape::getdatat()
{
   cout<<"enter tape title : ";
   getline(cin>>ws,title);
   cout<<"enter tape price : ";
   cin>>price;
   cout<<"enter tape playtime : ";
   cin>>playtime;
   try{
      
      if(price<=0 || playtime<=10)
	{
		throw (2);           
      	}
   }
   catch( int x)
   {
    cout<<"tape price cannot be zero or playtime cannot be less than 10"<<endl;	
	price=0;
	playtime=0;
	
   }

}
void book::putdatab()
{
   cout<<"display book details"<<endl;
   cout<<"title :="<<title<<endl;
   
   cout<<"price :="<<price<<endl;
   
   cout<<"pagecount :="<<pagecount<<endl;
   


   
}
void tape::putdatat()
{
   cout<<"display tape details"<<endl;
   cout<<"title :="<<title<<endl;
   
   cout<<"price :="<<price<<endl;
   
   cout<<"playtime :="<<playtime<<endl;
   

   
}

int main(){
    book b1[N];
    tape t1[N];
    cout<<"no. of entries"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
       b1[i].getdatab();
   
    }
    for(int i=0;i<n;i++){
       t1[i].getdatat();
   
    }
    for(int i=0;i<n;i++){
       b1[i].putdatab();
   
    }
   
    for(int i=0;i<n;i++){
       t1[i].putdatat();
   
    }
    /*b1.getdatab();
    t1.getdatat();
    b1.putdatab();
    t1.putdatat();*/

    return 0;

}
