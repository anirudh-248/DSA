#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    if (a<b) return a;
    else return b;
}

void main() {
    int n, D[50][50], i, j, k;
    printf("Enter the no of vertices: ");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d",&D[i][j]);
    for (k=0; k<n; k++)
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                D[i][j] = min(D[i][j], (D[i][k] + D[k][j]));
    printf("All Pairs Shortest Paths:\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%d ",D[i][j]);
        }
        printf("\n");
    }
}