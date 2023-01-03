#include <fstream> // Include filestream support.
#include <string> 
#include <iostream> 
using namespace std ; 
int main() { 
    string poem;
    ofstream fout("Poem.txt",ios::app); 
    if (!fout.is_open())
    {
        cerr <<"Error opening file for output"<< endl ; return -1 ;      // Signal an error then exit the program.
    }
    cout<<"\n\t Enter your Data here(type 'End'for end Data):";
        while(1) 
        {
            getline(cin,poem);
            if(poem=="End")
            break; 
            fout<<poem<< endl ;   // Write output. 
        } 
        fout.close() ;    // Close filestream*/
        ifstream fin("Poem.txt",ios::in);       //reading data
         if ( ! fin ) 
        {
                cout <<"Error opening file for input"<< endl ; 
                return -1 ;      // Signal an error then exit the program.
        }
        cout<<"\n File Contents are:\n";
        while(!fin.eof()) 
        {
            getline(fin,poem);
            cout<<"\n"<<poem;
        }     
    fin.close();
     return 0 ;
}