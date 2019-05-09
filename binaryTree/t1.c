#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}tnode;

void preorder(tnode*);
void inorder(tnode*);
void postorder(tnode*);
void insert(tnode*);
int search(tnode*, int);
void minimum(tnode*, int*);
void maximum(tnode*, int*);
void countleaves(tnode*, int*);

int main(){
    int ans, data, min, max;
    int count = 0;
    tnode* root = (tnode*)malloc(sizeof(tnode));
    printf("Enter the root data: ");
    scanf("%d", &root->data);
    root->left = root->right = NULL;
    insert(root);
    while (1){
        printf("\n1.PreOrder\n2.InOrder\n3.PostOrder\n4.Search\n5.Find Minminum and Maximum\n6.Count and print leaves\n7.exit\n");
        scanf("%d", &ans);
        switch(ans){
            case 1:
                preorder(root);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                postorder(root);
                break;
            case 4:
                printf("Enter the item you want to search: ");
                scanf("%d", &data);
                search(root, data);
                break;
            case 5:
                min = root->data;
                max = root->data;
                minimum(root, &min);
                maximum(root, &max);
                printf("minimum node is: %d\nmaximum node is: %d\n", min, max);
                break;
            case 6:
                countleaves(root, &count);
                printf("The number of leaf nodes is: %d\n", count);
                break;
            case 7:
                exit(0);
        }
    }
    return 0;
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

int search(tnode* root, int data){
    int i1, i2;
    if (root == NULL){
        printf("Item not found\n");
        return 0;
    }
    if (root->data == data){
        printf("Item found at node %d\n", root->data);
        return 1;
    }
    i1 = search(root->left, data);
    i2 = search(root->right, data);
    return i1 || i2;
}

void minimum(tnode* root, int* min){
    if (!root)
        return;
    minimum(root->left, min);
    if (root->data < *min)
        *min = root->data;
    minimum(root->right, min);
}

void maximum(tnode* root, int* max){
    if (!root)
        return;
    maximum(root->left, max);
    if (root->data > *max)
        *max = root->data;
    maximum(root->right, max);
}


void countleaves(tnode* root, int* count){
    tnode* ptr = root;
    if (!ptr->left && !ptr->right){
        (*count)++;
        return;
    }
    else{
        countleaves(root->left, count);
        countleaves(root->right, count);
    }
}

