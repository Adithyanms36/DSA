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

    if(root->left == NULL){
        root->left = insert(root->left, value);
    } else if(root->right == NULL){
        root->right = insert(root->right, value);
    } else {
        root->left = insert(root->left, value);
    }
    return root;
}

struct Node* delete(struct Node* root, int value){
    if(root == NULL){
        return NULL;
    }

    if(root->left && root->left->data == value){
        free(root->left);
        root->left = NULL;
        printf("Node %d deleted.\n", value);
        return root;
    }
    if(root->right && root->right->data == value){
        free(root->right);
        root->right = NULL;
        printf("Node %d deleted.\n", value);
        return root;
    }

    root->left = delete(root->left, value);
    root->right = delete(root->right, value);
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

int main() {
    struct Node* root = NULL;
    int choice, value;

    while(1){
        printf("Binary tree\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Inorder\n");
        printf("4.Preorder\n");
        printf("5.Postorder\n");
        printf("6.Exit\n");
        printf("Enter the choice : \n");
        scanf("%d", &choice);

        switch(choice) {
            case 1 :
                    printf("Enter the value to insert : ");
                    scanf("%d", &value);
                    root = insert(root, value);
                    break;
            case 2 :
                    printf("Enter the value to delete : ");
                    scanf("%d", &value);
                    root = delete(root, value);
                    break;
            case 3 :
                    printf("Inorder\n");
                    inorder(root);
                    printf("\n");
                    break;

            case 4 : 
                    printf("Preorder\n");
                    preorder(root);
                    printf("\n");
                    break;
            case 5 :
                    printf("Postorder\n");;
                    postorder(root);
                    printf("\n");
                    break;
            case 6 :
                    exit(0);
            default : 
                    printf("Invalid choice\n");
        }
    }
}