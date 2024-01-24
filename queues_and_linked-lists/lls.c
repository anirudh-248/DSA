//stacks using linked lists

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
    printf("Enter the data item: ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    return temp;
}

void push() {
    struct node *temp = create();
    if (start==NULL) {
        start = temp;
        printf("Item %d pushed to stack\n",temp->data);
    }
    else {
        struct node *temp1 = start;
        while (temp1->next!=NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        printf("Item %d pushed to stack\n",temp->data);
    }
}

void pop() {
    if (start==NULL) {
        printf("Stack empty\n");
    }
    else {
        struct node *prev, *temp = start;
        while (temp->next!=NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("Item %d popped from stack\n",temp->data);
        free(temp);
    }
}

void display() {
    if (start==NULL) {
        printf("Stack empty\n");
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

void main()
{
    int ch;
    printf("Stack operations:\n1.push  2.pop  3.display  4.exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("goodbye\n"); exit(0);
            default: printf("invalid choice\n");
        }
    }
}