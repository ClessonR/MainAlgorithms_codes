#include <iostream>
#include <string>



using namespace std;


class Node {
public:
    int value;
    Node *next;

    Node(int node_value, Node *node_pointer) {
        value = node_value;
        next = node_pointer;
    }
};

class Queue {
private:
    Node *head; //! Points to the first elemente in the Queue
    Node *tail; //! Points to the last element in the Queue
    // * The list order works like this:  first element(head) <- the rest of the elements <- last element(tail)
public:
    int num_elt;

    Queue() {
        head = nullptr;
        tail = nullptr;
        num_elt = 0;
    }

    ~Queue(){clear();}

    void clear(){
        while (tail != nullptr && tail->next != nullptr)
        {
            head = tail;
            tail = tail->next;
            delete head;
        }
        head = tail = nullptr;
        return;
    }

    void enqueue(int value){ //? Insert elements at the end of the Queue;
        if(head==tail && head == nullptr){//! Empty Queue
            Node *new_node= new Node(value, tail);
            tail = new_node;
            head = new_node;
            head->next =nullptr;
            num_elt++;
        }
        else{//! Already has elements
            Node *new_node= new Node(value, tail);
            tail = new_node;
            num_elt++;
        }


    }

    void dequeue(){ //? Removes the first elements from the Queue
        if (head == nullptr)
        {
            return;
        }
        Node* cur = tail;
        while (cur != head && cur->next != head)
        {
            cur = cur->next;
        }
         //! Value being popped;
        head = cur;
        cur = cur->next;

        num_elt --;
        return;

    }

    int first_val(){
        return(head->value);
    }
};




int main() {

    Queue *Left_S = new Queue;
    Queue *Right_S = new Queue;

    int n_cases, ferry_l, lines, temp_value; // * Number of cases, ferry_length, and placeholder;
    string side;
    int travels;
    int current_capacity;
    cin >> n_cases;

    for (int i = 0; i < n_cases; ++i) { //! Loop for each case
        travels = 0;
        current_capacity = 0;
        string ferry_status = "left"; //? The ferry always starts on the left;
        bool charge_condition;

        Left_S->clear(); //? Cleaning the Structs in order to always start with an empty Queue;
        Right_S->clear();

        cin >> ferry_l;
        cin >> lines;
        ferry_l = ferry_l * 100;

        for (int i = 0; i < lines; i++) //? Filling the Queues with the elements;
        {
            cin >> temp_value;
            cin >> side;
            if (side == "left"){
                Left_S->enqueue(temp_value);
            }
            else{
                Right_S->enqueue(temp_value);
            }

        }

        while (!((Left_S->num_elt == 0) && (Right_S->num_elt == 0))){
            //? While the Queue isn't empty perform the loop;
            charge_condition = true; // * The queue can be loaded;

            if (ferry_status == "left"){
                current_capacity = 0;
                while (charge_condition){ //! While the ferry can be loaded check these things:
                    if ((Left_S->num_elt != 0) && ((Left_S->first_val() + current_capacity) <= ferry_l)){
                        current_capacity = current_capacity + Left_S->first_val();
                        Left_S->dequeue();
                    }
                    else{
                        travels++;
                        charge_condition= false;
                        ferry_status = "right";
                    }
                }
            }
            else{
                current_capacity = 0;
                while (charge_condition)
                {
                    if (((Right_S->num_elt != 0) && ((Right_S->first_val() + current_capacity) <= ferry_l)))
                    {
                        current_capacity = current_capacity + Right_S->first_val();
                        Right_S->dequeue();
                    }
                    else
                    {
                        travels++;
                        charge_condition= false;
                        ferry_status = "left";
                    }
                }
            }


        }

        cout << travels << "\n";

    }


    //! Memory Dispensers;
    delete Left_S;
    delete Right_S;


    return 0;
}