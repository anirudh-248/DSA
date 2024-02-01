#include <stdio.h>
#include <stdlib.h>
#define size 5
int q[size],f=0,r=-1;

void insert() {
    if (r==size-1) {
        printf("Queue full\n");
    }
    else {
        int item;
        printf("Enter the item to insert: ");
        scanf("%d",&item);
        q[++r] = item;
        printf("Item %d inserted to queue\n",item);
    }
}

void delete() {
    if (f>r) {
        printf("Queue empty\n");
    }
    else {
        printf("Item %d deleted from queue\n",q[f++]);
    }
}

void peak() {
    if (f>r) {
        printf("Queue empty\n");
    }
    else {
        printf("Peak element: %d\n",q[f]);
    }
}

void display() {
    if (f>r) {
        printf("Queue empty\n");
    }
    else {
        for (int i=f; i<=r; i++) {
            printf("%d\t",q[i]);
        }
        printf("\n");
    }
}

void main() {
    int ch;
    printf("1.insert  2.delete  3.peak  4.display  5.exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: peak(); break;
            case 4: display(); break;
            case 5: printf("goodbye\n"); exit(0);
            default: printf("invalid choice\n");
        }
    }
}