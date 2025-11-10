#include <stdio.h>
#include <stdlib.h>
#define MAX 5 

int queue[MAX], front = -1, rear = -1;

void enqueue(int val){
    if(rear == MAX-1){
        printf("Overflow\n");
    } else{ 
        if(front == -1){
            front = rear = 0;
        } 
        else {
            rear++;
        }
        queue[rear] = val;
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Underflow\n");
    } else {
        front++;
        printf("Deleted Successfully\n");
    }
}

void display(){
    for(int i=front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){

    int choice;
    int val;

    while(1){
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter the choice : \n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1 : 
                    printf("Enter the number : ");
                    scanf("%d", &val);
                    enqueue(val);
                    break;
            case 2 : 
                    dequeue();
                    break;
            case 3 :
                    printf("Queue : ");
                    display();
                    break;
            case 4 : 
                    exit(0);
            default : 
                    printf("Invalid choice");
        }
    }

    return 0;
}