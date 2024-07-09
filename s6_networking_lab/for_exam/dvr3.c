#include <stdio.h>

int costMatrix[20][20], n;

struct router{
    int distance[20];
    int adjNode[20];
} nodes[20];

void readCostMatrix(){
    printf("Enter cost matrix: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &costMatrix[i][j]);
            costMatrix[i][i] = 0;
            nodes[i].distance[j] = costMatrix[i][j];
            nodes[i].adjNode[j] = j;
        }
    }
}

void calcRouterTable(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(nodes[i].distance[j] > costMatrix[i][k] + nodes[k].distance[j]){
                    nodes[i].distance[j] = nodes[i].distance[k] + nodes[k].distance[j];
                    nodes[i].adjNode[j] = k;
                }
            }
        }
    }
}

void displayRoutes(){
    for(int i = 0; i < n; i++){
        printf("\n\nRouter %d:", i + 1);
        for(int j = 0; j < n; j++){
            printf("\nNode %d via %d, Distance: %d", j + 1, nodes[i].adjNode[j] + 1, nodes[i].distance[j]);
        }
    }
}

int main(){
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);

    readCostMatrix();
    calcRouterTable();
    displayRoutes();

    return 0;
}