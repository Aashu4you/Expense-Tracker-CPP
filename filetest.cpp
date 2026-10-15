#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream fout("expenses.txt");

    if(!fout){
        cout<<"Error opening File"<<endl;
        return 1;
    }

    fout<<"Lunch 50 Food"<<endl;
    fout.close();
    return 0;
}