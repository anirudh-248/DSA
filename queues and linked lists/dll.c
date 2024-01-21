/*
Design, Develop and Implement a menu driven Program in C for the following operations on
Doubly Linked List (DLL) of Employee Data with the fields:
ID, Name, Dept, Designation, Sal, PhNo.
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue.
f. Exit
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    char name[20];
    int id;
    float sal;
    char phno[20];
    struct node *prev, *next;
};

struct node *start = NULL;

struct node *create() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter name: ");
    scanf("%s",temp->name);
    printf("Enter ID: ");
    scanf("%d",&temp->id);
    printf("Enter salary: ");
    scanf("%f",&temp->sal);
    printf("Enter phone number: ");
    scanf("%s",temp->phno);
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void ins_end() {
    struct node *temp = create();
    if (start==NULL) {
        start = temp;
    }
    else {
        struct node *temp1 = start;
        while (temp1->next!=NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
    }
}

void create_n_nodes() {
    int n;
    printf("Enter the no of employees: ");
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        ins_end();
    }
}

void display() {
    if (start==NULL) {
        printf("List empty\n");
    }
    else {
        struct node *temp = start;
        while (temp->next!=NULL) {
            printf("\nName: %s\nID: %d\nSalary: %.2f\nPhone number: %s\n\n",temp->name,temp->id,temp->sal,temp->phno);
            temp = temp->next;
        }
        printf("\nName: %s\nID: %d\nSalary: %.2f\nPhone number: %s\n\n",temp->name,temp->id,temp->sal,temp->phno);
    }
}

void count_nodes() {
    int n = 0;
    if (start==NULL) {
        n = 0;
    }
    else {
        struct node *temp = start;
        while (temp->next!=NULL) {
            n++;
            temp = temp->next;
        }
        n++;
    }
    printf("Total no of nodes: %d\n",n);
}

void del_end() {
    if (start==NULL) {
        printf("List empty\n");
    }
    else {
        struct node *temp = start;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void ins_front() {
    struct node *temp = create();
    if (start==NULL) {
        start = temp;
    }
    else {
        temp->next = start;
        start->prev = temp;
        start = temp;
    }
}

void del_front() {
    if (start==NULL) {
        printf("List empty\n");
    }
    else {
        struct node *temp = start;
        temp->next->prev = NULL;
        start = temp->next;
        free(temp);
    }
}

void deque() {
    int ch;
    printf("Demonstrating deque:\n1.insert front  2.delete front  3.insert end  4.delete end  5.display 6.return to main program\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: ins_front(); break;
            case 2: del_front(); break;
            case 3: ins_end(); break;
            case 4: del_end(); break;
            case 5: display(); break;
            case 6: printf("\n"); return;
            default: printf("invalid choice\n");
        }
    }
}

void main()
{
    int ch;
    create_n_nodes();
    printf("Employee details:\n");
    display();
    printf("\n1. display\n2. count nodes\n3. insert front\n4. insert end\n5.delete front\n6.delete end\n7. deque demonstration\n8. exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1: display(); break;
            case 2: count_nodes(); break;
            case 3: ins_front(); break;
            case 4: ins_end(); break;
            case 5: del_front(); break;
            case 6: del_end(); break;
            case 7: deque(); break;
            case 8: printf("goodbye\n"); exit(0);
            default: printf("invalid choice\n");
        }
    }
}