#include <iostream>
#include <string>

using namespace std;



class Node {
public:
    char value;
    Node *next;

    Node(char node_value, Node *node_pointer) {
        value = node_value;
        next = node_pointer;
    }
    Node(){
        value = NULL;
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


    void insert(char value){ //! Inserts a new element right at the cursor position;
        cur->next = new Node(value, cur->next);
        if (tail == cur){
            tail = cur->next;
        }
        elt++;
    }

    void append(char value) { //! Append an item to the end of the list;
        tail = tail->next = new Node(value, nullptr);
        elt++;
    }

    char remove(){ //? Removes the cursor item;
        char temp_val = cur->next->value;
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

    char getValue(){ //! Returns the current element;
        char val = cur->next->value;
        return (val);
    }

    void get_string(){
        Node* temp = head;
        while (temp->next!= nullptr){
            temp=temp->next;
            cout<< temp->value;
        }

    }


};



int main() {
    LList* text = new LList;

    string beiju;

    while (getline(cin, beiju)) { // ! Loop responsible for reading the beiju text, if there's an EOF it will stop;
        if (!cin) {
            break;
        }
        else
        {
            text->renew();
            for (int i = 0; i < beiju.length(); ++i)
            {
                if(beiju[i] == '['){
                    text->move_cur_start();
                }
                else if (beiju[i] == ']'){
                    text->move_cur_end();
                }
                else{
                    text->insert(beiju[i]);
                    text->move_cur_next();
                }







            }

            text->get_string();
            cout<< "\n";



        }
    }


    delete text;
    return 0;
}
