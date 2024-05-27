#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int a[], int low, int high) {
    int p,i,j,temp;
    p = a[low];
    i = low + 1;
    j = high;
    while (1) {
        while (p>=a[i] && i<high) {
            i++;
        }
        while (p<=a[j] && j>low) {
            j--;
        }
        if (i<j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

void quick_sort(int a[], int low, int high) {
    if (low < high) {
        int k = partition(a,low,high);
        quick_sort(a,low,k-1);
        quick_sort(a,k+1,high);
    }
}

void main() {
    clock_t start, end;
    int n,i,a[100000];
    printf("Enter the no of elems: ");
    scanf("%d",&n);
    srand(time(0));
    for (i=0; i<n; i++) {
        a[i] = rand()%100;
    }
    printf("Original array: ");
    for (i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    start = clock();
    quick_sort(a,0,n-1);
    end = clock();
    printf("\nSorted array: ");
    for (i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    float dur = (float)(end-start)/CLOCKS_PER_SEC;
    printf("\nTime taken: %f\n",dur);
}