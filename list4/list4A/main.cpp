#include <bits/stdc++.h>
using namespace std;

int index_main = 0;
long int items= 0;

struct Node{
    long int value;
    Node* left;
    Node* right;
    int height;
    int children;
};

class BSTree{

    Node* root;
    void clear(Node* a){ //? Clear all the bstree structure;
        if(a == NULL)
            return;
        clear(a->left);
        clear(a->right);
        delete a;
    }

    //! Functions for basic AVL things//

    int height( Node* a){ //? Return a node height;
        return (a == NULL ? -1 : a->height);
    }

    Node* one_right_rotation( Node* &main)
    {
        if(main->left != NULL){
        Node* temp = main->left;
        main->left = temp->right;
        temp->right = main;
        main->height= max(height(main->left), height(main->right))+1;
        temp->height = max(height(temp->left), main->height)+1;
        return temp;
        }
        return main;
    }

    Node* one_left_rotation( Node* &main)
    {
        if(main->right != NULL) {
            Node *temp = main->right;
            main->right = temp->left;
            temp->left = main;
            main->height = max(height(main->left), height(main->right)) + 1;
            temp->height = max(height(main->right), main->height) + 1;
            return temp;
        }
        return main;
    }

    Node* double_left_rotation ( Node* &main){
        main->right = one_right_rotation(main->right);
        return one_left_rotation(main);
    }

    Node* double_right_rotation( Node* &main){
        main->left = one_left_rotation(main->left);
        return one_right_rotation(main);
    }

    Node* find_min_value(Node* main){
        if(main == NULL)
            return  NULL;
        else if(main->right == NULL)
            return main;
        else return find_min_value(main->left);
    }

    Node* find_max_val(Node* main){
        if(main == NULL)
            return NULL;
        else if (main->right == NULL)
            return main;
        else return find_max_val(main->right);
    }



    Node* insert(long int item, Node* a)
    {
        if(a == NULL)
        {
            a = new Node;
            a->value = item;
            a->height =0;
            a->children =0;
            a->left = a->right = NULL;
        }
        else if( item == a->value) return  a;
        else if (item < a->value)
        {
            a->left = insert(item, a->left);
            if(height(a->left) - height(a->right) == 2)
            {
                if (item < a->left->value)
                    a = one_right_rotation(a);
                else
                    a = double_right_rotation(a);
            }
        }
        else if(item > a->value)
        {
            a->right = insert(item, a->right);
            if(height(a->right) - height(a->left) == 2)
            {
                if(item > a->right->value)
                    a = one_left_rotation(a);
                else
                    a = double_left_rotation(a);
            }
        }

        a->height = max(height(a->left) , height(a->right))+1;
        return a;
    }

    bool in_tree(Node* main, int to_be_found){
        if(main == NULL){
            return false;
        }
        if(main->value == to_be_found){
            return true;
        }
        else if(to_be_found < main->value)
            return in_tree(main->left,to_be_found);
        else
            return in_tree(main->right,to_be_found);

    }

    void find_item_index(Node* main, long int to_be_found)
    {
        if (main == NULL){
            //if(index_main == items){
            //    cout << "Data tidak ada";
            //}
            return;}

        find_item_index(main->left,to_be_found);
        if (main->value != to_be_found){
            index_main ++;
        }
        if (main->value == to_be_found){
            cout << index_main+1;
            return;
        }
        find_item_index(main->right,to_be_found);
    }





public:
    BSTree(){
        root = NULL;
    }

    void insert( long int value){
        root = insert(value,root);
    }

    void display_index(long int item)
    {
        find_item_index(root,item);
        cout << '\n';
    }

    bool is_in_tree(int value)
    {
        bool found = in_tree(root,value);
        return found;
    }




};




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BSTree *my_bst = new BSTree();

    long int cases;

    cin >> cases;

    int command, value;


    for (int i = 0; i < cases ; ++i) {
        cin >> command >> value;
        if(command == 1){
            my_bst->insert(value);
            items++;
        }
        else{
            if(my_bst->is_in_tree(value)){
                my_bst->display_index(value);
                index_main = 0;
            }
            else{
                cout << "Data tidak ada" << '\n';
            }
        }
    }

    delete my_bst;

    return 0;
}