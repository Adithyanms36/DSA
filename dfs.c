#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

void dfs(int node){
    printf("%d", node);
    visited[node] = 1;

    for(int i=0; i<n; i++){
        if(graph[node][i] == 1 && !visited[i]){
            dfs(i);
        }
    }
}

int main(){
    int u, v, choice, start;

    printf("Enter the nodes : ");
    scanf("%d", &n);

    while(1){
        printf("\n=== DFS Menu ===\n");
        printf("1. Add Edge\n");
        printf("2. Run DFS\n");
        printf("3. Display Graph\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                    printf("Enter the edge (u v)");
                    scanf("%d %d", &u, &v);
                    graph[u][v] = 1;
                    printf("Edge %d -> %d added!\n", u, v);
                    break;
            case 2:
                    for(int i=0; i<n; i++) visited[i] = 0;
                    printf("Enter the start node : ");
                    scanf("%d", &start);
                    printf("DFS");
                    dfs(start);
                    printf("\n");
                    break;
            case 3:
                    printf("Adjacency matrix\n");
                    for (int i = 0; i < n; i++)
                    {
                        printf("%d", i);
                        for (int j = 0; j < n; j++)
                        {
                            printf("%d", graph[i][j]);
                        }
                        printf("\n");
                        
                    }
                    break;
            case 4:
                    exit(0);
            default:
                    printf("Invalid choice");
        }
    }
    return 0;
}