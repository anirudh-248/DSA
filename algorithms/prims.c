#include <stdio.h>
int c[10][10], n;

void prims() {
    int vt[10] = {0};
    int a=0, b=0, min, mincost=0, ne=0, i, j;
    vt[0] = 1;
    while (ne < n-1) {
        min = 999;
        for (i=0; i<n; i++) {
            if (vt[i]==1) {
                for (j=0; j<n; j++) {
                    if (c[i][j] < min && vt[j]==0) {
                        min = c[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        printf("Edge from vertex %d to %d with cost = %d\n",a,b,min);
        vt[b] = 1;
        mincost += min;
        c[a][b] = c[b][a] = 999;
        ne++;
    }
    printf("Cost of MST: %d\n",mincost);
}

void main() {
    printf("Enter the no of vertices: ");
    scanf("%d",&n);
    printf("Enter the cost matrix:\n");
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            scanf("%d",&c[i][j]);
    prims(); 
}