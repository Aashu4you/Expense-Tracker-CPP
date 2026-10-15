#include <bits/stdc++.h>
#include <map>
#include <string>
using namespace std;

struct Expense
{
    int amount;
    string category;
    string expensename;

    Expense(int amount, string category, string expensename)
    {
        this->amount = amount;
        this->category = category;
        this->expensename = expensename;
    }
};

int main()
{

    bool menu = true;
    vector<Expense> expenseVector;
    while (menu)
    {
        cout << "========================================================" << endl;
        cout << "          Personal Expense Tracker          " << endl;
        cout << "========================================================" << endl;
        cout << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View All Expenses" << endl;
        cout << "3. View Total Spending" << endl;
        cout << "4. Filter expenses by category" << endl;
        cout << "5. Delete Expense" << endl;
        cout << "6. Exit" << endl;
        cout << endl;

        cout << endl;
        cout << "Enter your choice: ";
        int mychoice;
        cin >> mychoice;
        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid Input , Try again !!! \n";
            cout<<"Enter your choice: ";
            cin>>mychoice;
        }
        switch (mychoice)
        {
        case 1:
        {
            cout << "Adding Expense" << endl;
            string expenseName;
            int amount;
            string category;
            cout << "Expense Name: ";
            cin >> expenseName;
            cout << endl;
            cout<<"Enter amount: ";
            cin>>amount;
            while(cin.fail() || amount<=0){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Enter a valid amount(> 0): ";
                cin>>amount;
            }
            cout << endl;
            cout << "Category: ";
            cin >> category;
            Expense exp(amount, category, expenseName);
            expenseVector.push_back(exp);
            cout << endl;
            cout << "Added Successfully!!" << endl;
            break;
        }
        case 2:
        {
            cout << "All Expenses: " << endl;
            if (expenseVector.size() == 0)
            {
                cout << "No expense added yet!!" << endl;
                break;
            }
            for (const auto& e : expenseVector)
            {
                cout << e.expensename << " : " << e.amount << "  " << e.category << endl;
            }
            cout << "next choice? " << endl;
            break;
        }
        case 3:
        {
            cout << "Total Spending: ";
            int totalspending = 0;
            for (const auto& e : expenseVector)
            {
                totalspending += e.amount;
            }
            cout << totalspending << endl;
            cout << "next choice> ";
            cout<<endl;
            break;
        }
        case 4:
        {
            cout << "Expenses by Category: " << endl;
            unordered_map<string,int> categoryTotals;
            for(const auto& e: expenseVector){
                categoryTotals[e.category] += e.amount;
            }
            for(auto &it:categoryTotals){
                cout<<it.first<<" : "<<it.second<<endl;
            }
            cout<<endl;
            cout << "next choice? ";
            cout<<endl;
            break;
        }
        case 5:
        {
            cout << "Delete the expense: " << endl;
            if (expenseVector.size() == 0)
            {
                cout << "No expenses added yet!!" << endl;
                break;
            }
            for (const auto& e : expenseVector)
            {
                cout << e.expensename << " : " << e.amount << "  " << e.category << endl;
            }
            cout << "Enter the expense name you want to delete : ";
            bool deleted = false;
            string name;
            cin >> name;
            for (int i = 0; i < expenseVector.size(); i++)
            {
                if (expenseVector[i].expensename == name)
                {
                    expenseVector.erase(expenseVector.begin() + i);
                    deleted = true;
                    break;
                }
            }
            if(deleted){
                cout<<"Expense deleted Successfully!!"<<endl;
            }else{
                cout<<"Expense not found!"<<endl;
            }
            cout << "next choice? " << endl;
            break;
        }
        case 6:
        {
            menu = false;
            cout<<"Thanks for using the expense tracker";
            break;
        }
        default:
        {
            cout << "Enter a valid choice : "<<endl;
            cout<<endl;
        }
        }
    }
    return 0;
}
