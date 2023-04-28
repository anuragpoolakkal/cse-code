#include <stdio.h>
int graph[7][7] = {0};
int visited[10] = {0};

void addEdge(int v1, int v2)
{
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
}

void dfs(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (graph[i][j] == 1 && visited[j] == 0)
            dfs(j);
    }
}

int main()
{
    int e1, e2, op, d;
    do
    {
        printf("1.Create Edge\n2.DFS\n3.Exit\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter vertexes :");
            scanf("%d%d", &e1, &e2);
            addEdge(e1, e2);
            break;
        case 2:
            printf("Enter the vertex from which dfs should be applied : ");
            scanf("%d", &d);
            dfs(d);
            printf("\n");
            break;
        case 3:
            break;
        case 4:
            printf("Invalid option\n");
        }
    } while (op != 3);

    return 0;
}