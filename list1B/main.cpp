#include <iostream>

using namespace std;



class Node {
public:
    int value;
    Node *next;

    Node(int node_value, Node *node_pointer) {
        value = node_value;
        next = node_pointer;
    }
    Node(){
        value= NULL;
        next = nullptr;
    }
};


class LList{

public:
    Node* head;
    Node* tail;
    Node* cur;
    int elt;

    LList(){init();}
    ~LList(){clear();}

    void init(){ //? Initialize the linked list;
        cur = tail = head = new Node();
    }

    void clear(){ //? Clear all the contents inside the linked list;
        while (head != nullptr){
            cur = head;
            head = head->next;
            delete cur;
        }
    }

    void renew(){ //? Clear the existing linked list and make a new one;
        clear();
        init();
    }

    void print() const;

    void insert(int value){ //! Inserts a new element right at the cursor position;
        cur->next = new Node(value, cur->next);
        if (tail == cur){
            tail = cur->next;
        }
        elt++;
    }

    void append(int value) { //! Append an item to the end of the list;
        tail = tail->next = new Node(value, nullptr);
        elt++;
    }

    int remove(){ //? Removes the cursor item;
        int temp_val = cur->next->value;
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

    int getValue(){
        int val = cur->next->value;
        return (val);
    }


};



int main() {

    LList* test = new LList;





    delete test;
    return 0;
}
