#include <stdio.h>

void main() {
    int a[10],n,i,j,temp,item,mid,low,high,flag;
    printf("Enter the no of elems: ");
    scanf("%d",&n);
    printf("Enter the elems:\n");
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-i-1; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("Enter item to be searched: ");
    scanf("%d",&item);
    flag = 0;
    low = 0;
    high = n-1;
    while (low<=high) {
        mid = (low+high)/2;
        if (a[mid]==item) {
            flag = 1;
            break;
        }
        else if (item < a[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if (flag == 1) {
        printf("Item %d found\n",item);
    }
    else {
        printf("Item %d not found\n",item);
    }
}