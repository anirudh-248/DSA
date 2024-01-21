#include <stdio.h>
#include <stdlib.h>
#define size 5
int q[size],f=0,r=-1,count=0;

void insert() {
    if (count==size) {
        printf("Queue full\n");
    }
    else {
        int item;
        printf("Enter item to insert: ");
        scanf("%d",&item);
        r = (r+1)%size;
        q[r] = item;
        printf("Item inserted: %d\n",item);
        count++;
    }
}

void delete() {
    if (count==0) {
        printf("Queue empty\n");
    }
    else {
        printf("Item deleted: %d\n",q[f]);
        f = (f+1)%size;
        count--;
    }
}

void display() {
    if (count==0) {
        printf("Queue empty\n");
    }
    else {
        int j=f;
        for (int i=0; i<count; i++) {
            printf("%d\t",q[j]);
            j = (j+1)%size;
        }
        printf("\n");
    }
}

void main() {
    int ch;
    printf("1.insert  2.delete  3.display  4.exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("goodbye\n"); exit(0);
            default: printf("invalid choice\n");
        }
    }
}