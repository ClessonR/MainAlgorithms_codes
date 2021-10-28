#include <bits/stdc++.h>
using namespace std;

long long int hash_gen(string key){ //! Function that return the hashtable key;
    long long int h = 0;
    for (int i = 0; i < key.length() ; ++i) {
        h += (key[i] * (i+1));
    }
    h *= 19;
    return (h%101);
}


class Hash_table{
public:
    string main_array[101];
    int num_elt;
    int max_size;

    Hash_table(){
        num_elt =0;
        this->max_size = 101;
        for (int i = 0; i <max_size ; ++i) {
            main_array[i] = "empt";
        }
    }

    void clear(){ //! Reset the hashtable;
        for (int i = 0; i < this->max_size ; ++i) {
            main_array[i] = "empt";
        }
        num_elt =0;
    }
    void insert( long long int key, string word){ //! Insert a key into the hash table, and if already inserted nothing happens;
        int position;
        for (int i = 0; i < 20 ; ++i) {
            position = int((key + pow(i,2) + 23*i)) % 101;
            if(main_array[position] == word){
                return;}
            else{
                if(main_array[position] == "empt"){
                    main_array[position] = word;
                    num_elt++;
                    return;
                }

            }
        }

    }

    void del(string word, long long int key){ //! Deletes a key inside the hashtable;
        int position;
        for (int i = 0; i < 101 ; ++i) {
            position = int((key + pow(i,2) + 23*i)) % 101;
            if(main_array[position] == word){
                main_array[position] = "empt";
            num_elt--;
            return;}
        }
    }

    void table_show(){ //! Print all the items inside the hash table
        int items = 0;
        for (int j = 0; j < 101; ++j) {
            if(items == this->num_elt-1){
                if(main_array[j] != "empt"){
                    cout << j << ':' << main_array[j];
                    return;
                }
            }
            else if(main_array[j] != "empt"){
                cout << j << ':' << main_array[j] << "\n";
                items++;
            }

        }
    }
};





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Hash_table *my_table = new Hash_table;

    int cases, operations;
    string command;
    string word;
    long long int key;
    cin >> cases;
    for (int i = 0; i < cases ; ++i) {
        cin >> operations;
        for (int j = 0; j < operations ; ++j) {

            cin >> command;
            word = command.substr(4);
            command = command.substr(0,3);


            if(command == "ADD"){
                key = hash_gen(word);
                my_table->insert(key,word);
            }
            else{
                key = hash_gen(word);
                my_table->del(word,key);
            }
        }
        cout << my_table->num_elt << "\n";
        my_table->table_show();

        my_table->clear();
        if(i != cases -1){
            cout << '\n';
        }
    }


    delete my_table;


    return 0;
}