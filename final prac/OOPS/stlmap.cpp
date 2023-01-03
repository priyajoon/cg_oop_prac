#include <iostream>
#include <map>
#include<iomanip>
using namespace std;
int main()
{
typedef map<string, long> mapType;
mapType populationMap;
string states[]={"Uttar Pradesh","Maharashtra","Bihar","West Bengal","Andhra Pradesh","Madhya Pradesh","Tamil Nadu"},state;
long populations[]={199812341,112374333,104099452,91276115, 72147030,68548437,61095297},population;
for(int i=0;i<7;i++)
populationMap.insert(pair<string, long>(states[i],populations[i]));


int choice; 
char ch;
mapType::iterator iter = populationMap.begin();
do
{
    cout<<"*** Map Menus ***"<<endl;
    cout<<" 1. Display all States Population"<<endl;
    cout<<"2. Find Particular State Population"<<endl;
    cout<<"3. Update Population"<<endl;
    cout<<"4. Size of Population Map"<<endl;
    cout<<"5. Add another State Population"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<" Enter your choice:";
    cin>>choice;
    switch(choice){
    case 1: cout<<"\n\t"<<left<<setw(30)<<"State " <<setw(20)<<"Population"<<endl;
    for (iter = populationMap.begin(); iter != populationMap.end(); ++iter)
    cout <<"\t"<<left<<setw(30)<<iter->first <<setw(20)<< iter->second <<endl;
    break;
    case 2: cout<<"\n\t Enter the State Name:";
    fflush(stdin);
    getline(cin,state);
    iter = populationMap.find(state);
    if( iter != populationMap.end() )
    cout <<"\n\t "<<state <<"'s populations is "<< iter->second <<endl;
    else
    cout << "\n\t Key is not in populationMap" <<endl;
    break;
    case 3: cout<<"\n\t Enter the State Name:";
    fflush(stdin);
    getline(cin,state);
    cout<<"\n\t Enter Updated Population Count:";
    cin>>population;
    populationMap[state]=population;
    break;
    case 4: cout << "Size of populationMap: " << populationMap.size() ;
    break;
    case 5: cout<<"\n\t Enter the State Name:";
    fflush(stdin);
    getline(cin,state);
    cout<<"\n\t Enter Population Count:";
    cin>>population;
    populationMap.insert(pair<string, long>(state,population));
    break;
    case 6: exit(0);
    default:cout<<"\n\t Enter choice in between 1 to 5 only.";
    break;
}
    cout<<"\n\t Do you want to continue(y/n):";
    fflush(stdin);
    cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}

