#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Start with an empty list

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// ------------------ INSERTION FUNCTIONS ------------------

// Insert at the beginning
void insertAtFront(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("Node inserted at the front.\n");
}

// Insert at the end
void insertAtRear(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        printf("Node inserted at the rear.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Node inserted at the rear.\n");
}

// Insert at any given position
void insertAtPosition(int value, int position) {
    struct Node* newNode = createNode(value);

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at position %d.\n", position);
        return;
    }

    struct Node* temp = head;
    int i;
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", position);
}

// ------------------ DELETION FUNCTIONS ------------------

// Delete from the beginning
void deleteAtFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from front.\n");
}

// Delete from the end
void deleteAtRear() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Node deleted from rear.\n");
}

// Delete from any given position
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    if (position == 1) {
        head = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", position);
        return;
    }

    struct Node* prev = NULL;
    int i;
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", position);
}

// ------------------ DISPLAY FUNCTION ------------------

void displayList() {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ------------------ MAIN FUNCTION ------------------

int main() {
    int choice, value, position;

    do {
        printf("\n----- LINKED LIST MENU -----\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Front\n");
        printf("5. Delete at Rear\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtRear(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;

            case 4:
                deleteAtFront();
                break;

            case 5:
                deleteAtRear();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;

            case 7:
                displayList();
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 8);

    return 0;
}
