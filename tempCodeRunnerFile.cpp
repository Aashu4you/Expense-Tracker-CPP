case 4:
        {
            cout << "Expenses by Category: " << endl;
            unordered_map<string,int> map;
            for(const auto& e: expenseVector){
                map[e.category] += e.amount;
            }
            for(auto &it:map){
                cout<<it.first<<" : "<<it.second<<endl;
            }
            cout<<endl;
            cout << "next choice? ";
            break;
        }