/* C Program to demonstrate operations of Circular linked list with header node */
//Header node stores the number of nodes in the list 

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *create() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Entern the data item: ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    return temp;
}

void ins_front() {
    struct node *temp = create();
    if (head->next==NULL) {
        head->next = temp;
        temp->next = head;
        printf("Item %d inserted to front of list\n",temp->data);
    }
    else {
        temp->next = head->next;
        head->next = temp;
        head->data = head->data + 1;
        printf("Item %d inserted at front of list\n",temp->data);
    }
}

void del_front() {
    if (head->next==NULL) {
        printf("List empty\n");
    }
    else {
        struct node *temp = head->next;
        head->next = temp->next;
        head->data = head->data - 1;
        printf("Item %d deleted from front of list\n",temp->data);
        free(temp);
    }
}

void ins_end() {
    struct node *temp = create();
    if (head->next==NULL) {
        head->next = temp;
        temp->next = head;
        printf("Item %d inserted to end of list\n",temp->data);
    }
    else {
        struct node *temp1 = head->next;
        while (temp1->next!=head) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->next = head;
        head->data = head->data + 1;
        printf("Item %d inserted at the end of list\n",temp->data);
    }
}

void del_end() {
    if (head->next==NULL) {
        printf("List empty\n");
    }
    else {
        struct node *temp, *prev;
        temp = head->next;
        while (temp->next!=head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        head->data = head->data - 1;
        printf("Item %d deleted from end of list\n",temp->data);
        free(temp);
    }
}

void display() {
    if (head->next==NULL) {
        printf("List empty\n");
    }
    else {
        struct node *temp = head->next;
        while (temp->next!=head) {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        printf("%d\n",temp->data);
    }
}

void main()
{
    int ch;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;
    printf("1. insert front\n2. delete front\n3. insert end\n4. delete end\n5. display\n6. exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1: ins_front(); break;
            case 2: del_front(); break;
            case 3: ins_end(); break;
            case 4: del_end(); break;
            case 5: display(); break;
            case 6: printf("goodbye\n"); exit(0);
            default: printf("invalid choice\n");
        }
    }
}