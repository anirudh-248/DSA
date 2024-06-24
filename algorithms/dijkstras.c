#include <stdio.h>
int n,cost[100][100],s[100],d[100],src,i,j,v,w,min;

int minimum(int v, int w) {
    if (v < w) return v;
    else return w;
}

void dij() {
    for (i=0; i<n; i++) {
        d[i] = cost[src][i];
        s[i] = 0;
    }
    d[src] = 0;
    s[src] = 1;
    w = 0;
    for (i=0; i<n-1; i++) {
        min = 999;
        for (j=0; j<n; j++) {
            if (s[j]==0 && d[j]<min) {
                min = d[j];
                w = j;
            }
        }
        s[w] = 1;
        for (v=0; v<n; v++) {
            if (s[v]==0) {
                d[v] = minimum(d[v], d[w]+cost[w][v]);
            }
        }
    }
    printf("\nShortest distances from source %d:\n",src);
    for (i=0; i<n; i++) {
        printf("%d ",d[i]);
    }
    printf("\n");
}

void main() {
    printf("Enter the no of vertices: ");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d",&src);
    dij();
}