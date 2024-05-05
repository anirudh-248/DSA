#include <stdio.h>

void main() {
    int a[10],n,i,flag,item;
    printf("Enter the no of elems: ");
    scanf("%d",&n);
    printf("Enter the elems:\n");
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    printf("Enter the item to be searched: ");
    scanf("%d",&item);
    flag = 0;
    for (i=0; i<n; i++) {
        if (a[i]==item) {
            flag = 1;
            break;
        }
    }
    if (flag==1) {
        printf("Item %d found\n",item);
    }
    else {
        printf("Item %d not found\n",item);
    }
}