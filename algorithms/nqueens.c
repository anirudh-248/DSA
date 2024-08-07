#include <stdio.h>
#include <stdlib.h>

int place(int x[], int k) {
    for (int i=1; i<k; i++)
        if (x[i]==x[k] || abs(x[i]-x[k])==abs(i-k))
            return 0;
    return 1;
}

int nqueens(int n) {
    int x[10],k=1,ct=0;
    x[k] = 0;
    while (k!=0) {
        x[k]++;
        while (x[k]<=n && !place(x,k))
            x[k]++;
        if (x[k]<=n) {
            if (k==n) {
                printf("\nSolution %d:\n",++ct);
                for (int i=1; i<=n; i++) {
                    for (int j=1; j<=n; j++)
                        printf("%c ",j==x[i]?'Q':'x');
                    printf("\n");
                }
            }
            else x[++k] = 0;
        }
        else k--;
    }
    return ct;
}

void main() {
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("\nNo of possibilities are %d\n",nqueens(n));
}