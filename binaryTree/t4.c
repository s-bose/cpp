#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
}tnode;

tnode* insertBST(tnode*, int);
void preorder(tnode*);
void inorder(tnode*);
void postorder(tnode*);
tnode* searchBST(tnode*, int);
tnode* findleftmax(tnode*);
tnode* findrightmax(tnode*);
tnode* transplant(tnode*, tnode*, tnode*);
tnode* deleteBST(tnode*, tnode*);

int main(){
    int i, n, key, data;
    char ch;
    tnode *root = NULL; 
    printf("Enter the root node: ");
    scanf("%d", &data);
    root = insertBST(root, data);
    printf("Enter the node data, enter -1 to exit\n");
    while (1){
        scanf("%d", &data);
        if (data == -1)
            break;
        else 
            root = insertBST(root, data);
    } 
    while (1){
        printf("\n1.Preorder\n2.Inorder\n3.Postorder\n4.Search\n5.Find minimum and maximum\n6.Exit\n7.Insert more\n8.Delete\n");
        scanf("%d", &n);
        switch(n){
            case 1:
                printf("The preorder traversal is: \n");
                preorder(root);
                printf("\n");
                break;
            case 2:
                printf("The inorder traversal is: \n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("The postorder traversal is: \n");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the item you want to search: ");
                scanf("%d", &key);
                if (searchBST(root, key) != NULL)
                    printf("key found\n");                  
                else
                    printf("Key not found\n");
                 break;
            case 5:
                printf("The minimum element is: %d\nThe maximum element is: %d\n", findleftmax(root)->data, findrightmax(root)->data);
                break;
            case 6:
                exit(0);
            case 7:
                printf("Enter the data: ");
                scanf("%d", &data);
                root = insertBST(root, data);
                break;
            case 8:
                //printf("%d\n", root->data);
                printf("Enter the data you want to delete: \n");
                scanf("%d", &data);
                tnode* del;
                
                if ((del = searchBST(root, data)) == NULL){
                    printf("Error. Data not found\n");
                }

                else {
                    root = deleteBST(root, del);
                }
                printf("Inorder after deletion: \n");
                inorder(root);
                break;
            default:
                printf("Enter a valid option\n");
                break;       
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


tnode *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    temp->parent = NULL;
    return temp; 
} 

tnode* insertBST(tnode* root, int data){
   
   if (root == NULL){
        return newNode(data);
    }
    if (data == root->data)
        return root;
    else if (data < root->data){
       tnode* lc = insertBST(root->left, data);
       root->left = lc;
        lc->parent = root;
    }
    else {
        tnode* rc = insertBST(root->right, data);
        root->right = rc;
        rc->parent = root;
    }
    return root;
}

tnode* searchBST(tnode* root, int key){
    if (root == NULL || root->data  == key){
        return root;
    }
    else if (root->data > key)
        return searchBST(root->left, key);
    else 
        return searchBST(root->right, key);

}

tnode* findleftmax(tnode* node){
    tnode* curr = node;
    while (curr->left != NULL)
        curr = curr->left;
    return curr;
}

tnode* findrightmax(tnode* node){
    tnode* curr = node;
    while (curr->right != NULL)
        curr = curr->right;
    return curr;
}

tnode* transplant(tnode* root, tnode* u, tnode* v){
    if (u->parent == NULL)
        root = v;
    else if (u->parent->left == u)
        u->parent->left = v;
    else 
        u->parent->right = v;
    if (v != NULL)
        v->parent = u->parent;
    return root;
}


tnode* deleteBST(tnode* root, tnode* z){
    if (z->left == NULL)
        root = transplant(root, z, z->right);
    else if (z->right == NULL)
        root = transplant(root, z, z->left);
    else {
        tnode* y = findleftmax(z->right);
        if (y->parent != z){
            root = transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        root = transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y; 
    }
    return root;
}