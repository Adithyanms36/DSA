#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value){
    if(root == NULL){
        return createNode(value);
    }

    if(value < root->data){
        root->left = insert(root->left, value);
    } else if(value > root->data){
        root->right = insert(root->right, value);
    } else {
        printf("Duplicate value is not allowed\n");
    }
}

struct Node* search(struct Node* root, int key){
    if(root == NULL || root->data == key){
        return root;
    }

    if(key < root->data){
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

struct Node* findMin(struct Node* root){
    while(root && root->left != NULL){
        root = root->left;
    }
    return root;
}

struct Node* delete(struct Node* root, int key){
    if(root == NULL){
        return root;
    }

    if(key < root->data){
        root->left = delete(root->left, key);
    } else if(key > root->data){
        root->right = delete(root->right, key);
    } else {
        if(root->left == NULL){
            struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
            temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL){
            struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
            temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void inorder(struct Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    struct Node* root = NULL;
    int choice, value;

    while(1){
        printf("Binary Search Tree\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Search\n");
        printf("4.Inorder\n");
        printf("5.Preorder\n");
        printf("6.Postorder\n");
        printf("7.Exit\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1 : 
                    printf("Enter the value : ");
                    scanf("%d", &value);
                    root = insert(root, value);
                    break;
            case 2 : 
                    printf("Enter the value to delete : ");
                    scanf("%d", &value);
                    root = delete(root, value);
                    break;
            case 3 : 
                    printf("Enter the value to search: ");
                    scanf("%d", &value);
                    if(search(root, value) != NULL){
                        printf("Value at %d", value);
                    } else {
                        printf("Value no found");
                    }
                    break;
            case 4 : 
                    printf("Inorder\n");
                    inorder(root);
                    printf("\n");
                    break;
            case 5 :
                    printf("Preorder\n");
                    preorder(root);
                    printf("\n");
                    break;
            case 6:
                    printf("Postorder\n");
                    postorder(root);
                    printf("\n");
                    break;
            case 7 : 
                exit(0);
            default:
                    printf("Invalid choice\n");
        }
    }
    return 0;
}