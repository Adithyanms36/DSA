#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void insertAtFront() {
    int n;
    if(front == 0){
        printf("Overflow\n");
    } else {
        printf("Enter the number to insert : ");
        scanf("%d", &n);
        if(front == -1 && rear == -1){
            front = rear = 0;
            queue[front] = n;
        } else {
            front = front - 1;
            queue[front] = n;
        }  
    }
}

void insertAtRear() {
    int n;
    if(rear == MAX-1){
        printf("Overflow\n");
    } else {
        printf("Enter the number to insert : ");
        scanf("%d", &n);
        if(front == -1 && rear == -1){
            front = rear = 0;
            queue[rear] = n;
        } else {
            rear = rear + 1;
            queue[rear] = n;
        }  
    }
}

void deleteAtFront() {
    int n;
    if(front == -1 && rear == -1) {
        printf("Underflow\n");
    } else {
        n = queue[front];
        if(front == rear) {
            front = rear = -1;
        } else {
            front = front + 1;
        }
    }
}

void deleteAtRear() {
    int n;
    if(front == -1 && rear == -1) {
        printf("Underflow\n");
    } else {
        n = queue[rear];
        if(front == rear){
            front = rear = -1;
        } else {
            rear = rear - 1;
        }
    }
}

void display() {
    for(int i=front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    int choice;
    while(1) {
        printf("1.Insert at front\n");
        printf("2.Insert at rear\n");
        printf("3.Delete at front\n");
        printf("4.Delete at rear\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter your choice : \n");
        scanf("%d", &choice);

        switch(choice) {
            case 1 :
                    insertAtFront();
                    break;
            case 2 :
                    insertAtRear();
                    break;
            case 3 :
                    deleteAtFront();
                    break;
            case 4 :
                    deleteAtRear();
                    break;
            case 5 :
                    display();
                    break;
            case 6 :
                    exit(0);
        }

    }
    return 0;
}
