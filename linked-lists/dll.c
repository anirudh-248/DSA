/*
Design, Develop and Implement a menu driven Program in C for the following operations on
Doubly Linked List (DLL) of Employee Data with the fields:
SSN, Name, Dept, Designation, Sal, PhNo
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
    char ssn[20], name[20], dept[20], desg[20];
    float sal;
    int phno;
    struct node *prev, *next;
};

typedef struct node dll;
dll *start = NULL;

dll *create() {
    dll *temp;
    temp = (dll*)malloc(sizeof(dll));
    printf("Enter name: ");
    scanf("%s",temp->name);
    printf("Enter SSN: ");
    scanf("%s",temp->ssn);
    printf("Enter dept: ");
    scanf("%s",temp->dept);
    printf("Enter desg: ");
    scanf("%s",temp->desg);
    printf("Enter salary: ");
    scanf("%f",&temp->sal);
    printf("Enter phno: ");
    scanf("%d",&temp->phno);
    temp->prev = temp->next = NULL;
    return temp;
}

void ins_end() {
    dll *temp = create();
    if (start==NULL) {
        start = temp;
    }
    else {
        dll *temp1 = start;
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
    int ct=0;
    if (start==NULL) {
        printf("List empty\n");
    }
    else {
        dll *temp = start;
        while (temp->next!=NULL) {
            printf("\nName: %s\nSSN: %s\nDept: %s\nDesg: %s\nSalary: %.2f\nPhone number: %d\n",temp->name,temp->ssn,temp->dept,temp->desg,temp->sal,temp->phno);
            temp = temp->next;
            ct++;
        }
        ct++;
        printf("\nName: %s\nSSN: %s\nDept: %s\nDesg: %s\nSalary: %.2f\nPhone number: %d\n",temp->name,temp->ssn,temp->dept,temp->desg,temp->sal,temp->phno);
        printf("\nTotal no of nodes: %d\n",ct);
    }
}

void del_end() {
    if (start==NULL) {
        printf("List empty\n");
    }
    else if (start->next==NULL) {
        printf("Employee removed: %s\n",start->name);
        free(start);
        start = NULL;
    }
    else {
        dll *temp = start;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        printf("Employee removed: %s\n",temp->name);
        free(temp);
    }
}

void ins_front() {
    dll *temp = create();
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
    else if(start->next==NULL) {
        printf("Employee removed: %s\n",start->name);
        free(start);
        start = NULL;
    }
    else {
        dll *temp = start;
        start = temp->next;
        start->prev = NULL;
        printf("Employee removed: %s\n",temp->name);
        free(temp);
    }
}

void deque() {
    int ch;
    printf("1.insert front  2.insert rear  3.delete front  4.delete rear  5.display  6.return\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1: ins_front(); break;
            case 2: ins_end(); break;
            case 3: del_front(); break;
            case 4: del_end(); break;
            case 5: display(); break;
            case 6: printf("Returned to main program\n"); return;
            default: printf("invalid choice\n");
        }
    }
}

void main()
{
    int ch;
    create_n_nodes();
    printf("\nEMPLOYEE DETAILS:\n");
    display();
    printf("\nList operations:\n1.insert front  2.delete front  3.insert end  4.delete end  5.display  6.deque  7.exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1: ins_front(); break;
            case 2: del_front(); break;
            case 3: ins_end(); break;
            case 4: del_end(); break;
            case 5: display(); break;
            case 6: deque(); break;
            case 7: printf("goodbye\n"); exit(0);
            default: printf("invalid choice\n");
        }
    }
}