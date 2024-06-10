#include <stdio.h>

void main() {
    int n,i,j;
    printf("Enter the no of vertices: ");
    scanf("%d",&n);
    int a[n][n],visit[n],src[n],colsum[n];
    printf("Enter the adj matrix:\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for (i=0; i<n; i++) {
        visit[i] = 0;
        colsum[i] = 0;
    }
    for (int k=0; k<n; k++) {
        for (i=0; i<n; i++) {
            if (colsum[i]!=-1) {
                colsum[i] = 0;
            }
            for (j=0; j<n; j++) {
                colsum[i] += a[j][i];
            }
        }
        for (i=0; i<n; i++) {
            if (visit[i]==0 && colsum[i]==0) {
                src[k] = i+1;
                visit[i] = 1;
                colsum[i] = -1;
                for (j=0; j<n; j++) {
                    a[i][j] = 0;
                }
                break;
            }
        }
    }
    printf("Topological ordering: ");
    for (i=0; i<n; i++) {
        printf("%d ",src[i]);
    }
}