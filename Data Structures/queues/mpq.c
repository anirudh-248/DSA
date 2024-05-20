#include <stdio.h>
#include <stdlib.h>
#define size 5
int q[size],f=0,r=-1;

void ins_rear() {
    if (f>r) {
        f = 0;
        r = -1;
    }
    if (r==size-1) {
        printf("Queue overflow\n");
        return;
    }
    int item;
    printf("Enter item: ");
    scanf("%d",&item);
    int j=r;
    while (item < q[j] && f >= 0) {
        q[j+1] = q[j];
        j--;
    }
    q[++j] = item;
    r++;
    printf("Item %d inserted\n",item);
}

void del_front() {
    if (f>r) {
        printf("Queue underflow\n");
        f = 0; r = -1;
        return;
    }
    printf("Item %d deleted\n",q[f++]);
}

void display() {
    if (f>r) {
        printf("Queue empty\n");
        f=0; r=-1;
        return;
    }
    printf("Queue items:\n");
    for (int i=f; i<=r; i++) {
        printf("%d\t",q[i]);
    }
    printf("\n");
}

void main()
{
    int ch;
    printf("Minimum Priority Queue:\n1. insert  2.delete  3.display  4.exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1: ins_rear(); break;
            case 2: del_front(); break;
            case 3: display(); break;
            case 4: printf("goodbye\n"); exit(0);
            default: printf("invalid choice\n");
        }
    }
}