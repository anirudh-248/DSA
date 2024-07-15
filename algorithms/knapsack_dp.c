#include <stdio.h>
int n,m,w[10],p[10];

int max(int a, int b) {
    return (a>b?a:b);
}

void knapsack_dp() {
    int v[11][11],i,j;
    for (i=0; i<=n; i++) {
        for (j=0; j<=m; j++) {
            if (i==0 || j==0)
                v[i][j] = 0;
            else if (j<w[i-1])
                v[i][j] = v[i-1][j];
            else
                v[i][j] = max(v[i-1][j], p[i-1]+v[i-1][j-w[i-1]]);
        }
    }
    for (i=0; i<=n; i++) {
        for (j=0; j<=m; j++)
            printf("%d\t",v[i][j]);
        printf("\n");
    }
    printf("Items included: ");
    i = n; j = m;
    while (i>0) {
        if (v[i][j]!=v[i-1][j]) {
            printf("%d ",i);
            j -= w[i-1];
        }
        i--;
    }
    printf("\n");
}

void main() {
    printf("Enter the no of items: ");
    scanf("%d",&n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d",&m);
    printf("Enter the weights of the items: ");
    for (int i=0; i<n; i++)
        scanf("%d",&w[i]);
    printf("Enter the profits of the items: ");
    for (int i=0; i<n; i++)
        scanf("%d",&p[i]);
    knapsack_dp();
}