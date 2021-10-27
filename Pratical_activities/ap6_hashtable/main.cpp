#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    long int data;
    Node* next;

    Node(long int node_value, Node* node_pointer){
        this->data = node_value;
        this->next = node_pointer;
    }
    Node(){
        this->data = NULL;
        this->next = nullptr;
    }

};

class Llist{
public:
    Node* head;
    Node* tail;
    Node* cur;
    int elt;

    Llist(){init();}
    ~Llist(){clear();}


    void init(){
        cur=tail=head = new Node();
    }
    void clear(){
        while (head!= nullptr){
            cur = head;
            head = head->next;
            delete cur;
        }
    }

    void renew(){ //? Clear the existing linked list and make a new one;
        clear();
        init();
    }

    void insert(long int value){ //! Inserts a new element right at the cursor position;
        cur->next = new Node(value, cur->next);
        if (tail == cur){
            tail = cur->next;
        }
        elt++;
    }

    void append(long int value) { //! Append an item to the end of the list;
        tail = tail->next = new Node(value, nullptr);
        elt++;
    }

    long int remove(){ //? Removes the cursor item;
        long int temp_val = cur->next->data;
        Node* temp_node = cur->next;
        if (tail == cur->next) tail = cur;
        cur->next = cur->next->next;
        delete temp_node;
        elt--;
        return temp_val;
    }

    void move_cur_start(){
        cur =head;
    }
    void move_cur_end(){
        cur = tail;
    }

    void move_cur_prev(){
        if (cur == head) return;
        Node* temp_node = head;
        while (temp_node->next != cur) {temp_node = temp_node->next;}
        cur = temp_node;
    }

    void move_cur_next(){
        if (cur != tail) cur = cur->next;
    }

    long int getValue(){ //! Returns the current element;
        long int val = cur->next->data;
        return (val);
    }

    void get_items(){
        Node* temp = head;
        while (temp->next!= nullptr){
            temp=temp->next;
            if(temp->data != NULL){
            cout<< temp->data << " ";}
        }
        cout << "\n";
    }
};

class Hash_table{
public:
    Llist* main_array;
    int num_elt;

    Hash_table(int size){
        this->main_array = new Llist[size];
    }
    ~Hash_table(){delete[] main_array;}

};

long int hash_function(long int k){
    long int key = k % 10;
    return key;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    Hash_table* my_table = new Hash_table(size);

    int temp;
    for (int i = 0; i < size ; ++i) {
        cin >> temp;
        my_table->main_array[hash_function(temp)].append(temp);
    }
    for (int i = 0; i < size ; ++i) {
        cout << i << " ";
        my_table->main_array[i].get_items();
    }

    delete my_table;



    return 0;
}