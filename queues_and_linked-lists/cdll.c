#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *start = NULL;

struct node *create() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data item: ");
    scanf("%d",&temp->data);
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void ins_front() {
    struct node *temp = create();
    if (start==NULL) {
        start = temp;
        start->next = start;
        start->prev = start;
    }
    else {
        temp->prev = start->prev;
        start->prev->next = temp;
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
    printf("Item %d inserted to front of list\n",temp->data);
}

void del_front() {
    if (start==NULL) {
        printf("List empty\n");
    }
    else if (start->next==start) {
        printf("Item %d deleted from front of list\n",start->data);
        free(start);
        start = NULL;
    }
    else {
        struct node *temp = start;
        start = temp->next;
        temp->prev->next = start;
        start->prev = temp->prev;
        printf("Item %d deleted from front of list\n",temp->data);
        free(temp);
    }
}

void ins_end() {
    struct node *temp = create();
    if (start==NULL) {
        start = temp;
        start->next = start;
        start->prev = start;
    }
    else {
        start->prev->next = temp;
        temp->prev = start->prev;
        temp->next = start;
        start->prev = temp;
    }
    printf("Item %d inserted to end of list\n",temp->data);
}

void del_end() {
    if (start==NULL) {
        printf("List empty\n");
    }
    else if (start->next==start) {
        printf("Item %d deleted from end of list\n",start->data);
        free(start);
        start = NULL;
    }
    else {
        struct node *temp = start->prev;
        start->prev = temp->prev;
        temp->prev->next = start;
        printf("Item %d deleted from end of list\n",temp->data);
        free(temp);
    }
}

void display() {
    if (start==NULL) {
        printf("List empty\n");
    }
    else {
        printf("List items:\n");
        struct node *temp = start;
        while (temp->next!=start) {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
}

void rev_display() {
    if (start==NULL) {
        printf("List empty\n");
    }
    else {
        printf("List items:\n");
        struct node *temp = start;
        while (temp->prev!=start) {
            temp = temp->prev;
            printf("%d\t",temp->data);
        }
        printf("%d\n",temp->prev->data);
    }
}

void main()
{
    int ch;
    printf("CDLL operations:\n1. insert front\n2. delete front\n3. insert end\n4. delete end\n5. display\n6. reverse display\n7. exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1: ins_front(); break;
            case 2: del_front(); break;
            case 3: ins_end(); break;
            case 4: del_end(); break;
            case 5: display(); break;
            case 6: rev_display(); break;
            case 7: printf("goodbye\n"); exit(0);
            default: printf("invalid choice\n");
        }
    }
}