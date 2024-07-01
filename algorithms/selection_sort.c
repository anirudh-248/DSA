#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int n,i,j,min,temp;
    printf("Enter the no of elems: ");
    scanf("%d",&n);
    int a[n];
    srand(time(0));
    for (i=0; i<n; i++)
        a[i] = rand()%100;
    printf("Unsorted array: ");
    for (i=0; i<n; i++)
        printf("%d ",a[i]);
    for (i=0; i<n-1; i++) {
        min = i;
        for (j=i+1; j<n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
    printf("\nSorted array: ");
    for (i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
}