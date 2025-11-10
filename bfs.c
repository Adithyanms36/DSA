#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int queue[MAX], front = -1, rear = -1;

void enqueue(int val){
    if(rear == MAX-1) return;
    if(front == -1) front = 1;
    queue[++rear] = val;
}

int dequeue(){
    if(front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty(){
    return front == -1 || front > rear;
}

void bfs(int graph[MAX][MAX], int n, int start){
    int visited[MAX] = {0};

    printf("BFS traversal : ");
    enqueue(start);
    visited[start] = 1;

    while(!isEmpty()){
        int node = dequeue();
        printf("%d", node);

        for(int i=0; i<n; i++){
            if(graph[node][i] == 1 && !visited){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
    front = rear = -1;
}

void displayGraph(int graph[MAX][MAX], int n){
    printf("\nGraph (Adjacency Matrix):\n   ");

    for(int i=0; i<n; i++) printf("%d", i);
    printf("\n");

    for(int i=0; i<n; i++){
        printf("%d: ", i);
        for(int j=0; j<n; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    return 0;
}