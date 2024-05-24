#include <stdio.h>
int c[10];
void merge(int a[], int low, int mid, int high) {
    int i = low;
    int j = mid+1;
    int k = 0;
    while (i<=mid && j<=high) {
        if (a[i] < a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }
    while (i<=mid) {
        c[k++] = a[i++];
    }
    while (j<=high) {
        c[k++] = a[j++];
    }
    k = 0;
    for (i = low; i <= high; i++) {
        a[i] = c[k++];
    }
}

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a, low, mid, high);
    }
}

void main() {
    int n,a[10];
    printf("Enter the no of elems: ");
    scanf("%d",&n);
    printf("Enter the elems: ");
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    printf("Unsorted array: ");
    for (int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
    mergesort(a,0,n-1);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}