#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin("expenses.txt");
    if(!fin){
        cout<<"Error opening the file"<<endl;
        return 1;
    }
    string line;
    while(getline(fin,line)){
        cout<<line<<endl;
    }
    fin.close();
    return 0;
}