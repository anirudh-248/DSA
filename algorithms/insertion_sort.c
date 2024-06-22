#include <stdio.h>

void main() {
    int n, i, j, v;
    printf("Enter the no of elems: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elems: ");
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    printf("Original array: ");
    for (i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    for (i=1; i<n; i++) {
        v = a[i];
        j = i - 1;
        while (j>=0 && a[j]>v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
    printf("\nSorted array: ");
    for (i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}