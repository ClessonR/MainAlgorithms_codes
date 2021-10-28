#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* lefttree;
    Node* righttree;
    Node(int val){
        this->data = val;
        lefttree = nullptr;
        righttree = nullptr;
    }
};

class BSTree{
public:
    Node* Root;
    int nodecount; //! Number of nodes inside the BST;

    BSTree(){
        Root = NULL, nodecount =0;
    }
    ~BSTree(){ clearhelp(this->Root);}

    void clear(){
        clearhelp(this->Root);
        this->Root = NULL;
    }

    void insert(int element){
        this->Root = inserthelp(this->Root,element);
    }

    void print() {
        if(this->Root == NULL) cout << "Empty BST";
        else{
            printhelp(this->Root,0);
        }
    }

    int findhelp(Node* root, int find)
    {
        if(root == NULL) return  NULL;
        if (find < root->data)
            return findhelp(root->lefttree,find);
        else if(find > root->data)
            return findhelp(root->righttree, find);
        else return root->data;
    }

    Node* inserthelp(Node* root, int insert){
        if (root == NULL){
            root = new Node(insert);
        }
        if (insert < Root->data){
            root->lefttree=inserthelp(root->lefttree,insert);
        }
        else
        {
            root->righttree = inserthelp(root->righttree,insert);
        }
        return root;
    }

    void clearhelp(Node* root){
        if(root == NULL) return;
        clearhelp(root->lefttree);
        clearhelp(root->righttree);
        delete root;
    }

    void printhelp(Node* Root, int level){
        if(Root == NULL) return;
        printhelp(Root->lefttree, level+1);
        for (int i = 0; i < level ; ++i) {
            cout << " ";
        }
        cout << Root->data << "\n";
        printhelp(Root->righttree, level+1);

    }


};




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BSTree * my_tree = new BSTree;
    my_tree->insert(37);
    my_tree->insert(24);
    my_tree->insert(7);
    my_tree->insert(2);
    my_tree->insert(32);
    my_tree->insert(42);
    my_tree->insert(40);
    my_tree->insert(43);
    my_tree->insert(10);



    return 0;
}