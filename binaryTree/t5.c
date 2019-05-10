#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
    int threadnode;
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
    int i, ans, data, mode;
    int* arr = (int*)malloc(sizeof(int));
    tnode* root = (tnode*)malloc(sizeof(tnode));
    tnode* key, *succ, *pred;
    printf("Enter the root data: ");
    scanf("%d", &root->data);
    root->left = root->right = root->parent = NULL;
    root->threadnode = 0;
    insert(root);
    printf("The inorder traversal is: \n");
    inorder(root);

    printf("\n1.inorder threading one way\n2.inorder threading two way\n3.preorder threading one way\n4.preorder threading two way\n");
    scanf("%d", &ans);
    switch(mode){
        case 1:
            threaded_oneway_inord(root, root);
            break;
        case 2:
            threaded_twoway_inord(root, root);
            break;
        case 3:
            threaded_oneway_preord(root, root);
            break;
        case 4:
            threaded_twoway_preord(root, root);
            break;
    }
    while (1){
        printf("\n1.PreOrder successor\n2.InOrder successor\n3.PostOrder successor\n4.InOrder predecessor\n5.PreOrder predecessor\n6.PostOrder predecessor\n7.exit\n");
        scanf("%d", &ans);
        switch(ans){
            case 1:
                printf("The preorder display is: \n");
                preorder(root);
                printf("\n");
                printf("Enter the node you want to find preorder successor of: ");
                scanf("%d", &data);
                key = findnode(root, data);
                if (key->threadnode == 1 &&  (mode == 3 || mode == 4)) {
                    //preorder threading one way or two way
                    succ = key->right;
                    printf("the preorder successor of %d is %d\n", data, succ->data);
                    break;
                }
                else {
                    succ = preordersuccessor(key, root);
                    if (succ == NULL)
                        {
                            printf("No preorder successor for this node\n");
                            break;
                        }    
                    printf("the preorder successor of %d is %d\n", data, succ->data);
                    break;
                }
            case 2:
                printf("The inorder display is: \n");
                inorder(root);
                printf("\n");
                printf("Enter the node you want to find inorder successor of: ");
                scanf("%d", &data);
                key = findnode(root, data);
                if (key->threadnode == 1 &&  (mode == 1 || mode == 2)) {
                    //inorder threading one way or two way
                    succ = key->right;
                    printf("the inorder successor of %d is %d\n", data, succ->data);
                    break;
                }
                else {
                    succ = inordersuccessor(key, root);
                    if (succ == NULL)
                        {
                            printf("No preorder successor for this node\n");
                            break;
                        }    
                    printf("the preorder successor of %d is %d\n", data, succ->data);
                    break;
                }
                case 3:
                    printf("The postorder display is: \n");
                    postorder(root);
                    printf("\n");
                    printf("Enter the node you want to find postorder successor of: ");
                    scanf("%d", &data);
                    key = findnode(root, data);
                    succ = postordersuccessor(key, root);
                    if (succ == NULL)
                        {
                            printf("No postorder successor for this node\n");
                            break;
                        }    
                    printf("the postorder successor of %d is %d\n", data, succ->data);
                    break;
                case 4:
                    printf("The inorder display is: \n");
                    inorder(root);
                    printf("\n");
                    printf("Enter the node you want to find inorder predecessor of: ");
                    scanf("%d", &data);
                    key = findnode(root, data);
                    if (key->threadnode == 1 &&  mode == 2) {
                        //inorder threading two way
                        pred = key->left;
                        printf("the inorder predecessor of %d is %d\n", data, pred->data);
                        break;
                    }
                    else {
                        pred = inorderpredecessor(key, root);
                        if (pred == NULL)
                            {
                                printf("No inorder predecessor for this node\n");
                                break;
                            }    
                        printf("the inorder predecessor of %d is %d\n", data, pred->data);
                        break;
                    }
                case 5:
                    printf("The preorder display is: \n");
                    preorder(root);
                    printf("\n");
                    printf("Enter the node you want to find preorder predecessor of: ");
                    scanf("%d", &data);
                    key = findnode(root, data);
                    if (key->threadnode == 1 && mode == 4) {
                        //preorder threading two way
                        pred = key->left;
                        printf("the preorder predecessor of %d is %d\n", data, pred->data);
                        break;
                    }
                    else {
                        pred = preorderpredecessor(key, root);
                        if (pred == NULL)
                            {
                                printf("No preorder predecessor for this node\n");
                                break;
                            }    
                        printf("the preorder predecessor of %d is %d\n", data, pred->data);
                        break;
                    }
                case 6:
                    printf("The postorder display is: \n");
                    postorder(root);
                    printf("\n");
                    printf("Enter the node you want to find postorder predecessor of: ");
                    scanf("%d", &data);
                    key = findnode(root, data);
                    succ = postorderpredecessor(key, root);
                    if (succ == NULL)
                        {
                            printf("No postorder predecessor for this node\n");
                            break;
                        }    
                    printf("the postorder predecessor of %d is %d\n", data, succ->data);
                    break;
                case 7:
                    exit(0);
        }

    }
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
        ptr->threadnode = 0;
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
        ptr->threadnode = 0;
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
    if (node->right == NULL){
        node->right = inordersuccessor(node, root);
        node->threadnode = 1;
    }
        
    threaded_oneway_inord(node->left, root);
    threaded_oneway_inord(node->right, root);
}

tnode* threaded_twoway_inord(tnode* node, tnode* root){
    if (node->left == NULL){
        node->left = inorderpredecessor(node, root);
        node->threadnode = 1;
    }
        
    if (node->right == NULL){
        node->right = inordersuccessor(node, root);
        node->threadnode = 1;
    }
        
    threaded_twoway_inord(node->left, root);
    threaded_twoway_inord(node->right, root);
}

tnode* threaded_oneway_preord(tnode* node, tnode* root){
    if (node->right == NULL){
        node->right = preordersuccessor(node, root);
        node->threadnode = 1;
    }
    threaded_oneway_preord(node->left, root);
    threaded_oneway_preord(node->right, root);
}

tnode* threaded_twoway_preord(tnode* node, tnode* root){
    if (node->left == NULL){
        node->left = preorderpredecessor(node, root);
        node->threadnode = 1;
    }
        
    if (node->right == NULL){
        node->right = preordersuccessor(node, root);
        node->threadnode = 1;
    }
    threaded_twoway_preord(node->left, root);
    threaded_twoway_preord(node->right, root);
}