#include <stdio.h>

void main() {
    int a[10],i,j,n,min,temp;
    printf("Enter the no of elems in the array: ");
    scanf("%d",&n);
    printf("Enter the array elems:\n");
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    printf("Array before sorting:\n");
    for (i=0; i<n; i++) {
        printf("%d\t",a[i]);
    }
    for (i=0; i<n-1; i++) {
        min = i;
        for (j=i+1; j<n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min!=i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    printf("\nArray after sorting:\n");
    for (i=0; i<n; i++) {
        printf("%d\t",a[i]);
    }
    printf("\n");
}