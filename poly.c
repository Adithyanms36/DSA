#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int expo;
    struct node* link;
};

struct node *Phead, *Qhead, *Rhead;

struct node* ReadPoly(){
    struct node *new, *ptr, *head=NULL, *prev;
    int n, i;

    printf("Enter the total number of terms in polynomial : ");
    scanf("%d", &n);

    printf("Enter the coefficient and exponents in the polynomial : ");
    for(i=1; i<=n; i++){
        printf("Enter (coef%d, expo%d)", i, i);
        new = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &new->coeff);
        scanf("%d", &new->expo);
        new->link = NULL;
        if(head == NULL){
            head = new;
            ptr = head;
        } else {
            ptr->link = new;
            ptr = new;
        }
    }
    return head;
}

void DisplayPoly(struct node* head){
    struct node *ptr;
    if(head == NULL){
        printf("Polynomial is empty");
    } else {
        ptr = head;
        while(ptr->link != NULL){
            printf("%dx^%d + ", ptr->coeff, ptr->expo);
            ptr = ptr->link;
        }
        printf("%dx^%d\t", ptr->coeff, ptr->expo);
    }
}

struct node* AddPoly() {
    struct node *new, *P, *Q, *R, *head=NULL;
    P = Phead;
    Q = Qhead;
    while(P!=NULL && Q!=NULL){
        if(P->expo == Q->expo){
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = P->coeff + Q->coeff;
            new->expo = P->expo;
            P = P->link;
            Q = Q->link;
        } else if(P->expo > Q->expo){
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = P->coeff;
            new->expo = P->expo;
            new->link = NULL;
            P = P->link;
        } else {
            new = (struct node*)malloc(sizeof(struct node));
            new->coeff = Q->coeff;
            new->expo = Q->expo;
            new->link = NULL;
            Q = Q->link;
        }
        if(head == NULL){
            head = new;
            R = head;
        } else {
            R->link = new;
            R = new;
        }
    }
    while(P != NULL){
        new = (struct node*)malloc(sizeof(struct node));
        new->coeff = P->coeff;
        new->expo = P->expo;
        new->link = NULL;
        if(head == NULL){
            head = new;
            R = new;
        } else {
            R->link = new;
            R = new;
        }
        P = P->link;
    }
    while(Q != NULL) {
        new = (struct node*)malloc(sizeof(struct node));
        new->coeff = Q->coeff;
        new->expo = Q->expo;
        new->link = NULL;
        if(head == NULL){
            head = new;
            R = new;
        } else {
            R->link = new;
            R = new;
        }
        Q = Q->link;
    }
    return head;    
}

int main() {

    printf("Enter the details of first polynomial : \n");
    Phead = ReadPoly();
     
    printf("Enter the details of second polynomial : ");
    Qhead = ReadPoly();

    printf("First Polynomial : ");
    DisplayPoly(Phead);
    printf("Second Polynomial : ");
    DisplayPoly(Qhead);

    Rhead = AddPoly();
    printf("Resultant polynomial : ");
    DisplayPoly(Rhead);

    return 0;
}