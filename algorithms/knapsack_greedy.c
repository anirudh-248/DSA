#include <stdio.h>
int n,m,w[10],p[10];

void knapsack() {
    float max,profit=0,x[10]={0},con_flag=1;
    int i,j,k;
    for (i=0; i<n; i++) {
        max = 0;
        for (j=0; j<n; j++) {
            if ((float)p[j]/w[j] > max) {
                max = (float)p[j]/w[j];
                k = j;
            }
        }
        if (w[k]<=m) {
            x[k] = 1;
            m -= w[k];
            profit += p[k];
        }
        else {
            if (con_flag) {
                x[k] = (float)m/w[k];
                printf("\nContinuous solution:\nItems included:\n");
                for (j=0; j<n; j++)
                    if (x[j]) 
                        printf("Item %d, portion %f\n",j+1,x[j]);
                printf("Profit = %f\n",profit+x[k]*p[k]);
                con_flag = 0;
                x[k] = 0;
            }
        }
        p[k] = 0;
    }
    printf("\nDiscrete solution:\nItems included:\n");
    for (j=0; j<n; j++)
        if (x[j])
            printf("%d ",j+1);
    printf("\nProfit = %f\n",profit);
}

void main() {
    printf("Enter the no of items: ");
    scanf("%d",&n);
    printf("Enter the weights: ");
    for (int i=0; i<n; i++)
        scanf("%d",&w[i]);
    printf("Enter the profits: ");
    for (int i=0; i<n; i++)
        scanf("%d",&p[i]);
    printf("Enter capacity: ");
    scanf("%d",&m);
    knapsack();
}