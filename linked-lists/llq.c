//queues using linked lists

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node *create() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data item: ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    return temp;
}

void ins_rear() {
    struct node *temp = create();
    if (start==NULL) {
        start = temp;
        printf("Item %d inserted to queue\n",temp->data);
    }
    else {
        struct node *temp1 = start;
        while (temp1->next!=NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        printf("Item %d inserted to queue\n",temp->data);
    }
}

void del_front() {
    if (start==NULL) {
        printf("Queue empty\n");
    }
    else {
        struct node *temp = start;
        start = temp->next;
        printf("Item %d deleted from queue\n",temp->data);
        free(temp);
    }
}

void display() {
    if (start==NULL) {
        printf("Queue empty\n");
    }
    else {
        struct node *temp = start;
        while (temp->next!=NULL) {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
}

void main() {
    int ch;
    printf("Queue operations:\n1.insert rear  2.delete front  3.display  4.exit\n");
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