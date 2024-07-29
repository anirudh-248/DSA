#include <stdio.h>
int min(int a, int b) {
    return (a<b?a:b);
}
void main() {
    int n,d[10][10],i,j,k;
    printf("Enter the no of vertices: ");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%d",&d[i][j]);
    for (k=0; k<n; k++)
        for (i=0; i<n; i++)
            for (j=0; j<n; j++)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    printf("All Pairs Shortest Paths:\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++)
            printf("%d\t",d[i][j]);
        printf("\n");
    }
}