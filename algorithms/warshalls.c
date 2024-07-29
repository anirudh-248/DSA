#include <stdio.h>
void main() {
    int n,t[10][10],i,j,k;
    printf("Enter the no of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d",&t[i][j]);
    for (k=0; k<n; k++)
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                t[i][j] = t[i][j] || (t[i][k] && t[k][j]);
    printf("Transitive closure:\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++)
            printf("%d\t",t[i][j]);
        printf("\n");
    }
}