#include <stdio.h>
int n,m,w[100],p[100];

int max(int a, int b) {
    return (a>b?a:b);
}

void knapsack_dp() {
    int v[100][100],i,j;
    for (i=0; i<=n; i++) {
        for (j=0; j<=m; j++) {
            if (i==0 || j==0)
                v[i][j] = 0;
            else if (j<w[i])
                v[i][j] = v[i-1][j];
            else
                v[i][j] = max(v[i-1][j], p[i]+v[i-1][j-w[i]]);
        }
    }
    for (i=0; i<=n; i++) {
        for (j=0; j<=m; j++)
            printf("%d\t",v[i][j]);
        printf("\n");
    }
    printf("Items included: ");
    while (n>0) {
        if (v[n][m]!=v[n-1][m]) {
            printf("%d ",n);
            m -= w[n];
        }
        n--;
    }
}

void main() {
    printf("Enter the no of items: ");
    scanf("%d",&n);
    printf("Enter the weights of the items: ");
    for (int i=1; i<=n; i++)
        scanf("%d",&w[i]);
    printf("Enter the profits of the items: ");
    for (int i=1; i<=n; i++)
        scanf("%d",&p[i]);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d",&m);
    knapsack_dp();
}