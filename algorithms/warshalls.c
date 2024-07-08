#include <stdio.h>
#include <stdlib.h>
void main() {
    int n, A[50][50], i, j, k;
    printf("Enter the no of vertices: ");
    scanf("%d",&n);
    printf("Enter the adj matrix:\n");
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d",&A[i][j]);
    for (k=0; k<n; k++)
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                A[i][j] = A[i][j] || (A[i][k] && A[k][j]);
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (A[i][j]==0) {
                printf("\nGraph is not connected\n");
                exit(0);
            }
        }
    }
    printf("\nGraph is connected\n");
}