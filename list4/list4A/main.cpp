#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
    int item;
    int l_child;
    int r_child;
    int height;
    struct Node *left;
    struct Node *right;

} Node;


int height (Node *root) {
    return (root == NULL) ? 0 : root -> height;
}

int max (int a, int b) {
    return a > b ? a : b;
}

int show_balance_fac (Node *root) {
    if (root == NULL) return 0;
    else return height(root -> left) - height(root -> right);
}

Node *new_Node (int item, int l_child, int r_child) {
    Node *tmp_Node = (Node *) malloc( sizeof(Node) );
    tmp_Node -> item = item;
    tmp_Node -> left = NULL;
    tmp_Node -> right = NULL;
    tmp_Node -> height = 1;
    tmp_Node -> l_child = l_child;
    tmp_Node -> r_child = r_child;
    return tmp_Node;
}

Node *left_rotation (Node *main) {
    Node *sec_main = main -> right;
    Node *second_tree = sec_main -> left;

    sec_main -> left = main;
    main -> right = second_tree;

    main -> height = max( height(main -> left), height(main -> right) ) + 1;
    sec_main -> height = max( height(sec_main -> left), height(sec_main -> right) ) + 1;

    if (second_tree != NULL) main -> r_child = second_tree -> l_child + second_tree -> r_child + 1; else main -> r_child = 0;
    sec_main -> l_child = main -> l_child + main -> r_child + 1;

    return sec_main;
}

Node *right_rotation (Node *main) {
    Node *sec_main = main -> left;
    Node *second_tree = sec_main -> right;

    sec_main -> right = main;
    main -> left = second_tree;

    main -> height = max( height(main -> left), height(main -> right) ) + 1;
    sec_main -> height = max( height(sec_main -> left), height(sec_main -> right) ) + 1;

    if (second_tree != NULL) main -> l_child = second_tree -> l_child + second_tree -> r_child + 1; else main -> l_child = 0;
    sec_main -> r_child = main -> l_child + main -> r_child + 1;

    return sec_main;
}

short int temp_var;

int main_find (Node *root, int item) {
    if (root != NULL) {
        if (item > root -> item) return root -> l_child + 1 + main_find(root -> right, item);
        else if (item < root -> item) return main_find(root -> left, item);
        else return root -> l_child;
    } else {
        temp_var = 1;
        return -1;
    };
}

Node *insert(Node *root, int item) {

    if (root == NULL) return new_Node(item, 0, 0);
    if (item < root -> item) {
        root -> left = insert(root -> left, item);
        root -> l_child++;
    }
    else if (item > root -> item) {
        root -> right = insert(root -> right, item);
        root -> r_child++;
    }
    else return root;

    root -> height = max( height(root -> left), height(root -> right) ) + 1;

    int balance = show_balance_fac(root);


    if ( (balance > 1) && (item < root -> left -> item) ) return right_rotation(root);

    if ( (balance < -1) && (item > root -> right -> item) ) return left_rotation(root);

    if ( (balance > 1) && (item > root -> left -> item) ) {
        root -> left = left_rotation(root -> left);
        return right_rotation(root);
    }

    if ( (balance < -1) && (item < root -> right -> item) ) {
        root -> right = right_rotation(root -> right);
        return left_rotation(root);
    }

    return root;
}


int main () {
    int n;
    scanf("%d", &n);
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        short int command;
        int value;
        scanf("%hd%d", &command, &value);
        if (command == 1) {

            root = insert(root, value);
        }
        if (command == 2) {
            temp_var = 0;
            int ind = main_find(root, value) + 1;
            if (temp_var) printf("Data tidak ada\n"); else printf("%d\n", ind);
        }

    }

    return 0;
}