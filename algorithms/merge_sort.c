#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int c[100000], ct=0;

void merge(int a[], int low, int mid, int high) {
    int i=low,j=mid+1,k=0;
    while (i<=mid && j<=high) {
        ct++;
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = a[j++];
    }
    while (i<=mid)
        c[k++] = a[i++];
    while (j<=high)
        c[k++] = a[j++];
    k = 0;
    for (i=low; i<=high; i++)
        a[i] = c[k++];
}

void merge_sort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low+high)/2;
        merge_sort(a, low, mid);
        merge_sort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

void main() {
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
    merge_sort(a,0,n-1);
    printf("\nSorted array: ");
    for (i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    printf("\nNo of comparisons: %d\n",ct);
}