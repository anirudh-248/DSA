#include <stdio.h>
int x[10],w[10],ct=0,d;

void sos(int s, int k, int rem) {
    x[k] = 1;
    if (s+w[k]==d) {
        printf("subset %d:\n",++ct);
        for (int i=0; i<=k; i++)
            if (x[i]==1)
                printf("%d ",w[i]);
        printf("\n");
    }
    else if (s+w[k]+w[k+1]<=d)
        sos(s+w[k], k+1, rem-w[k]);
    if (s+rem-w[k]>=d && s+w[k+1]<=d) {
        x[k] = 0;
        sos(s, k+1, rem-w[k]);
    }
}

void main() {
    int n,sum=0,i;
    printf("Enter the no of items: ");
    scanf("%d",&n);
    printf("Enter the items: ");
    for (i=0; i<n; i++) {
        scanf("%d",&w[i]);
        sum += w[i];
    }
    printf("Enter the sum: ");
    scanf("%d",&d);
    if (sum < d || w[0] > d)
        printf("no subsets\n");
    else
        sos(0,0,sum);
}