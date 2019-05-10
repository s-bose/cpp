#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
}tnode;



void insert(tnode*);
void preorder(tnode*);
void inorder(tnode*);
void postorder(tnode*);
tnode* preordersuccessor(tnode*, tnode*);
tnode* inordersuccessor(tnode*, tnode*);
tnode* postordersuccessor(tnode*, tnode*);
tnode* preorderpredecessor(tnode*, tnode*);
tnode* inorderpredecessor(tnode*, tnode*);
tnode* postorderpredecessor(tnode*, tnode*);
tnode* threaded_oneway_inord(tnode*, tnode*);
tnode* threaded_twoway_inord(tnode*, tnode*);
tnode* threaded_oneway_preord(tnode*, tnode*);
tnode* threaded_twoway_preord(tnode*, tnode*);

tnode* findmin(tnode*);
tnode* findmax(tnode*);
tnode* findnode(tnode* root, int data){
    if (root == NULL)
        return NULL;
    if (root->data == data)
        return root;
    else {
        tnode* t1, *t2;
        t1 = findnode(root->left, data);
        t2 = findnode(root->right, data);
        if (t1 != NULL)
            return t1;
        else 
            return t2;
    }
}

int main(){
    int i, ans, data;
    int* arr = (int*)malloc(sizeof(int));
    tnode* root = (tnode*)malloc(sizeof(tnode));
    tnode* key, *succ;
    printf("Enter the root data: ");
    scanf("%d", &root->data);
    root->left = root->right = root->parent = NULL;
    insert(root);
    printf("The inorder traversal is: \n");
    inorder(root);
    
    return 0;

}

tnode* findmin(tnode* node){
    tnode* curr = node;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

tnode* findmax(tnode* node){
    tnode* curr = node;
    while (curr->right != NULL)
        curr = curr->right;
    return curr;
}

void insert(tnode* root){
    tnode* ptr;
    char ch;
    int data;
    printf("Do you want to insert in left child of %d : (y/n)", root->data);
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y'){
        ptr = (tnode*)malloc(sizeof(tnode));
        printf("Enter the data: ");
        scanf("%d", &ptr->data);
        ptr->left = ptr->right = NULL;
        root->left = ptr;
        ptr->parent = root;
        insert(root->left);
    }
    else if (ch == 'n' || ch == 'N')
        root->left = NULL;

    printf("Do you want to insert in right child of %d : (y/n)", root->data);
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y'){
        ptr = (tnode*)malloc(sizeof(tnode));
        printf("Enter the data: ");
        scanf("%d", &ptr->data);
        ptr->left = ptr->right = NULL;
        root->right = ptr;
        ptr->parent = root;
        insert(root->right);
    }
    else if (ch == 'n' || ch == 'N')
        root->right = NULL;
}



void preorder(tnode* root){
    if (root == NULL)
        return;
    printf("%d , ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(tnode* root){
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d , ", root->data);
    inorder(root->right);
}

void postorder(tnode* root){
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d , ", root->data);
}


tnode* preordersuccessor(tnode* node, tnode* root){
    if (node->left)
        return node->left;
    else if (!node->left && node->right)
        return node->right;
    else {
        tnode* current = node, *p = current->parent;
        while (p != NULL && p->right == current){
            current = current->parent;
            p = p->parent;
        }
        if (p == NULL)
            return NULL;
        return p->right;
    }
}

tnode* preorderpredecessor(tnode* node, tnode* root){
    if (node == root)
        return NULL;
    if (node->left == NULL || node->left == node)
        return node->parent;
    else {
        tnode* curr = node->parent->left;
        while (curr->left != NULL)
            curr = curr->right;
        return curr;
    }
}

tnode* inordersuccessor(tnode* node, tnode* root){
    if (node->right){
        tnode* curr = node->right;
        while (curr->left != NULL)
            curr = curr->left;
        return curr;
    }
    else {
        tnode* curr = node;
        while (curr->parent != NULL && curr->parent->right == curr){
            curr = curr->parent;
        }
        if (curr->parent == NULL)
            return NULL;
        return curr->parent;
    }
}

tnode* inorderpredecessor(tnode* node, tnode* root){
    if (node->left){
        tnode* curr = node->left;
        if (curr->right)
            return findmax(curr);
        return curr;
    }
    else {
        tnode* curr = node;
        tnode* parent = curr->parent;
        while (parent != NULL && curr->parent->left == curr){
            curr = curr->parent;
            parent = parent->parent;
        }
        if (parent == NULL)
            return NULL;
        return parent;
    }
}

tnode* postordersuccessor(tnode* node, tnode* root){
    if (node == root)   
        return NULL;
    else if (node->parent->right == node || node->parent->right == NULL)
        return node->parent;
    else {
        return findmin(node->parent->right);
    }
}

tnode* postorderpredecessor(tnode* node, tnode* root){
    if (node->right)
        return node->right;
    else if (node->left)
        return node->left;
    else {
        tnode* curr = node;
        tnode* parent = curr->parent;
        while (parent != NULL && parent->right != node){
            curr = curr->parent;
            parent = parent->parent;
        }
        if (parent == NULL)
            return NULL;
        return findmax(parent->left);
    }
}


tnode* threaded_oneway_inord(tnode* node, tnode* root){
    if (node->right == NULL)
        node->right = inordersuccessor(node, root);
    threaded_oneway(node->left, root);
    threaded_oneway(node->right, root);
}

tnode* threaded_twoway_inord(tnode* node, tnode* root){
    if (node->left == NULL)
        node->left = inorderpredecessor(node, root);
    if (node->right == NULL)
        node->right = inordersuccessor(node, root);
    threaded_twoway(node->left, root);
    threaded_twoway(node->right, root);
}

tnode* threaded_oneway_preord(tnode* node, tnode* root){
    if (node->right == NULL)
        node->right = preordersuccessor(node, root);
    threaded_oneway_preord(node->left, root);
    threaded_oneway_preord(node->right, root);
}

tnode* threaded_twoway_preord(tnode* node, tnode* root){
    if (node->left == NULL)
        node->left = preorderpredecessor(node, root);
    if (node->right == NULL)
        node->right = preordersuccessor(node, root);
    threaded_twoway_preord(node->left, root);
    threaded_twoway_preord(node->right, root);
}