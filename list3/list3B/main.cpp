#include <bits/stdc++.h>
using namespace std;

class BSTree{
public:
    int value;
    class BSTree *leftnode;
    class BSTree *rightnode;
};

BSTree* insert(BSTree *main_tree, int input_val) //? Inserts a random number into the BSTree given that it's in preorder
{
    BSTree *new_root = new BSTree(); //? Every new node is a new BST;
    new_root->value = input_val;

    if(main_tree->value == 0){
        main_tree->value = input_val;
    }
    else if (input_val < (main_tree->value) ){
        if( main_tree ->leftnode == NULL){
            main_tree ->leftnode = new_root;
        }else {
            insert(main_tree->leftnode,input_val);
        }
        }
    else{
        if(main_tree->rightnode == NULL){
            main_tree->rightnode = new_root;
        }
        else{
            insert(main_tree->rightnode, input_val);
        }
    }
    return new_root;

}

void post_order(BSTree *main_tree){ //? To print the BST in post_order;
    if(main_tree){
        post_order(main_tree->leftnode);
        post_order(main_tree->rightnode);
        cout << main_tree->value << '\n';
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int value;
    BSTree* tree = new BSTree();

    while (cin >> value){
        insert(tree,value);
    }

    post_order(tree);

    return 0;

}