#include <stdio.h>
#include <stdlib.h>
#define size 5
int q[size],f=0,r=-1;

void ins_rear() {
    if (f>r) {
        f = 0; r = -1;
    }
    if (r==size-1) {
        printf("Queue full\n");
    }
    else {
        int item;
        printf("Enter item to insert: ");
        scanf("%d",&item);
        q[++r] = item;
        printf("Item inserted: %d\n",item);
    }
}

void del_front() {
    if (f>r) {
        f = 0; r = -1;
        printf("Queue empty\n");
    }
    else {
        printf("Item deleted: %d\n",q[f++]);
    }
}

void ins_front() {
    if (f>r) {
        f = 0; r = -1;
    }
    if (f==0) {
        printf("Cannot insert\n");
    }
    else {
        int item;
        printf("Enter item to insert: ");
        scanf("%d",&item);
        q[--f] = item;
        printf("Item inserted: %d\n",item);
    }
}

void del_rear() {
    if (f>r) {
        f = 0; r = -1;
        printf("Queue empty\n");
    }
    else {
        printf("Item deleted: %d\n",q[r--]);
    }
}

void display() {
    if (f>r) {
        f = 0; r = -1;
        printf("Queue empty\n");
    }
    else {
        for (int i=f; i<=r; i++) {
            printf("%d\t",q[i]);
        }
        printf("\n");
    }
}

void main()
{
    int ch;
    printf("1.insert rear  2.delete front  3.insert front  4.delete rear  5.display  6.exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1: ins_rear(); break;
            case 2: del_front(); break;
            case 3: ins_front(); break;
            case 4: del_rear(); break;
            case 5: display(); break;
            case 6: printf("goodbye\n"); exit(0);
            default: printf("Invalid choice\n");
        }
    }
}