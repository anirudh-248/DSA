#include <stdio.h>
int cost[10][10],d[10],n;

int minimum(int a, int b) {
    return (a<b?a:b);
}

void dijkstra(int src) {
    int min,i,j,w=0,s[10]={0};
    for (i=0; i<n; i++)
        d[i] = cost[src][i];
    s[src] = 1;
    for (i=0; i<n-1; i++) {
        min = 999;
        for (j=0; j<n; j++) {
            if (s[j]==0 && min>d[j]) {
                min = d[j];
                w = j;
            }
        }
        s[w] = 1;
        for (int v=0; v<n; v++)
            if (s[v]==0 && cost[w][v]!=999)
                d[v] = minimum(d[v], d[w]+cost[w][v]);
    }
}

void main() {
    int src,i,j;
    printf("Enter no of vertices: ");
    scanf("%d",&n);
    printf("Enter cost matrix:\n");
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d",&cost[i][j]);
    printf("Enter source vertex: ");
    scanf("%d",&src);
    dijkstra(src);
    printf("Shortest distances from the source:\n");
    for (i=0; i<n; i++)
        printf("%d ",d[i]);
    printf("\n");
}