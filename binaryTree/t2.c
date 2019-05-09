#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}tnode;



void insert(tnode*);
void preorder(tnode*);
void inorder(tnode*);
void postorder(tnode*);
void iterative_preorder(tnode*);
void iterative_inorder(tnode*);
void iterative_postorder(tnode*);
//void iterative_preorder_2(tnode*);


int main(){
    int ans;
    tnode* root = (tnode*)malloc(sizeof(tnode));
    printf("Enter the root data: ");
    scanf("%d", &root->data);
    root->left = root->right = NULL;
    insert(root);
    while (1){
        printf("\n1.PreOrder\n2.InOrder\n3.PostOrder\n4.exit\n");
        scanf("%d", &ans);
        switch(ans){
            case 1:
                iterative_preorder(root);
                break;
            case 2:
                iterative_inorder(root);
                break;
            case 3:
                iterative_postorder(root);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
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
        insert(root->left);
    }
    else if (ch == 'n' || ch == 'N')
        root->left = NULL;

    printf("Do youn want to insert in right child of %d : (y/n)", root->data);
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y'){
        ptr = (tnode*)malloc(sizeof(tnode));
        printf("Enter the data: ");
        scanf("%d", &ptr->data);
        ptr->left = ptr->right = NULL;
        root->right = ptr;
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


void iterative_preorder(tnode* root){
    tnode* stack[MAX];
    int top = 0;
    if (root == NULL)
        return;
    tnode* ptr = root;
    stack[top++] = NULL;
    while (ptr != NULL){
        printf("%d , ", ptr->data);
        if (ptr->right)
            stack[top++] = ptr->right;
        if (ptr->left)
            ptr = ptr->left;
        else
            ptr = stack[--top];
    }
}

/*
void iterative_preorder_2(tnode* root){
    tnode* stack[MAX];
    int top = 0;
    if (root == NULL)
        return;
    stack[top++] = root;
    while (top != 0){
        tnode* ptr = stack[--top];
        printf("%d , ", ptr->data);
        if (ptr->right)
            stack[top++] = ptr->right;
        if (ptr->left)
            stack[top++] = ptr->left;
        
    }
}
*/

void iterative_inorder(tnode* root){
    if (root == NULL)
        return;
    tnode* stack[MAX];
    int top = 0;
    tnode* ptr = root;
    while (ptr != NULL || top != 0){
        while (ptr != NULL){
            stack[top++] = ptr;
            ptr = ptr->left;
        }
        ptr = stack[--top];
        printf("%d , ", ptr->data);
        ptr = ptr->right;
    }
}

void iterative_postorder(tnode* root){
    if (root == NULL)
        return;
    tnode* stack[MAX];
    int top = 0;
    tnode* ptr = root;
    while (top != 0 || ptr != NULL){
        while (ptr != NULL){
            if (ptr->right)
                stack[top++] = ptr->right;
            stack[top++] = ptr;
            ptr = ptr->left;
        }
        ptr = stack[--top];
        if (ptr->right && stack[top-1] == ptr->right){
            stack[--top];
            stack[top++] = ptr;
            ptr = ptr->right;
        }
        else {
            printf("%d , ", ptr->data);
            ptr = NULL;
        }
    }
}
