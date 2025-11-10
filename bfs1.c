#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int queue[MAX], front = -1, rear = -1;

void enqueue(int val){
    if(rear == MAX-1) return;
    if(front == -1) front=0;
    queue[++rear] = val;
}

int dequeue(){
    if(front==-1 || front > rear) return -1;
    return queue[++front]; 
}

int isEmpty(){
    return front==-1 || front > rear;
}

void bfs(int graph[MAX][MAX], int n, int start){
    int visited[MAX] = {0};

    printf("BFS Traversal : ");
    enqueue(start);
    visited[start] = 1;

    while(!isEmpty()){
        int node = dequeue();
        printf("%d", node);

        for(int i=0; i<n; i++){
            if(graph[node][i] == 1 && !visited[i]){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
    front = rear = -1;
}

void displayGraph(int graph[MAX][MAX], int n){
    printf("Graph\n");
    for(int i=0; i<n; i++) printf("%d", i);
    printf("\n");

    for(int i=0; i<n ; i++){
        for(int j=0; j<n; j++){
            printf("%d", graph[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int graph[MAX][MAX] = {0};
    int n=0, choice, u, v, start;
    
    printf("Enter the number of nodes : ");
    scanf("%d", &n);

    while(1){
         printf("\n=== BFS Menu ===\n");
        printf("1. Add Edge\n");
        printf("2. Run BFS\n");
        printf("3. Display Graph\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                    printf("Enter the edge (u v) : ");
                    scanf("%d %d", &u, &v);
                    if(u>=0 && u<n && v>=0 && v<n){
                        graph[u][v] = 1;
                        printf("Edage %d -> %d added\n", u, v);
                    } else {
                        printf("Invalid nodes");
                    }
                    break;
            case 2:
                    printf("Enter the starting node : ");
                    scanf("%d", &start);
                    if(start >= 0 && start < n){
                        bfs(graph, n, start);
                    } else {
                        printf("Invalide node\n");
                    }
                    break;
            case 3:
                    displayGraph(graph, n);
                    break;
            case 4:
                    printf("Exit");
                    exit(0);
            default:
                    printf("Invalid choice!!\n");

        }
    }

    return 0;
}