#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff, expo;
    struct node *link;
};

struct node *Phead, *Qhead, *Rhead;

struct node* ReadPoly(){
    struct node *new, *ptr, *head = NULL;
    int n, i;

    printf("Enter the term for polynomial : ");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter the coeff%d and expo%d : ", i, i);
        new = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &new->coeff);
        scanf("%d", &new->expo);
        new->link = NULL;
        if(head == NULL){
            head = new;
            ptr = head;
        } else {
            ptr = ptr->link;
            ptr = new;
        }
    }
    return head;
}

void DisplayPoly(struct node* head){
    struct node* ptr;
    if(head == NULL){
        printf("Polynomial is empty");
    } else {
        ptr = head;
        while(ptr->link != NULL){
            printf("%dx^%d", ptr->coeff, ptr->expo);
            ptr = ptr->link;
        }
        printf("%dx^%d", ptr->coeff, ptr->expo);
    }
}

struct node* MulPoly(){
    struct node *P, *Q, *new, *R, *prev, *head = NULL;
    P = Phead;
    Q = Qhead;
    while(P != NULL){
        Q = Qhead;
        while(Q != NULL){
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = P->coeff * Q->coeff;
            new->expo = P->expo + Q->expo;
            new->link = NULL;
            if(head == NULL){
                head = new;
                R = head;
            } else {
                R->link = new;
                R = new;
            }
            Q = Q->link;
        }
        P = P->link;
    }

    P = head;

    while(P != NULL){
        prev = P;
        Q = P->link;
        while(Q != NULL){
            if(P->expo == Q->expo){
                P->coeff = P->coeff + Q->coeff;
                prev->link = Q->link;
                free(Q);
                Q = prev->link;
            } else {
                prev = Q;
                Q = Q->link;
            }
        }
        P = P->link;
    }   
    return head;
}

int main() {
    printf("\nEnter the details of first polynomial : ");
    Phead = ReadPoly();

    printf("\nEnter the details of second polynomial : ");
    Qhead = ReadPoly();

    printf("\nFirst polynomial : ");
    DisplayPoly(Phead);

    printf("\nSecond polynomial : ");
    DisplayPoly(Qhead);

    Rhead = MulPoly();
    printf("\nMultiplied polynomial : ");
    DisplayPoly(Rhead);

    return 0;
}