#include <stdio.h>
#include <stdlib.h>

void main() {
    int a[25],i,j,n,temp,e;
    printf("Enter the no of elems in the array: ");
    scanf("%d",&n);
    printf("Enter the array elements:\n");
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    printf("The array before sorting:\n");
    for (i=0; i<n; i++) {
        printf("%d\t",a[i]);
    }
    for (i=0; i<n-1; i++) {
        e = 0;
        for (j=0; j<n-i-1; j++) {
            if (a[j] > a[j+1]) {
                e++;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if (e==0) break;
    }
    printf("\nThe array after sorting:\n");
    for (i=0; i<n; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
}