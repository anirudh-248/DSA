/*
Menu driven Program in C for the following operations on Singly Linked List (SLL) of Student
Data with the fields: USN, Name, Programme, Sem, PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL 
d. Perform Insertion / Deletion at Front of SLL
e. Exit
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    char name[20];
    char usn[20];
    char branch[20];
    int sem;
    char phno[20];
    struct node *next;
};

struct node *start = NULL;

struct node *create() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\n");
    printf("Enter name: ");
    scanf("%s",temp->name);
    printf("Enter USN: ");
    scanf("%s",temp->usn);
    printf("Enter branch: ");
    scanf("%s",temp->branch);
    printf("Enter semester: ");
    scanf("%d",&temp->sem);
    printf("Enter phone number: ");
    scanf("%s",temp->phno);
    printf("\n");
    temp->next = NULL;
    return temp;
}

void ins_front() {
    struct node *temp = create();
    if (start==NULL) {
        start = temp;
    }
    else {
        temp->next = start;
        start = temp;
    }
}

void create_n_nodes() {
    int n;
    printf("Enter the no of students: ");
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        ins_front();
    }
}

void display() {
    if (start==NULL) {
        printf("List empty\n");
    }
    else {
        struct node *temp = start;
        while (temp->next!=NULL) {
            printf("\nName: %s\nUSN: %s\nBranch: %s\nSemester: %d\nPhone number: %s\n\n",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
            temp = temp->next;
        }
        printf("\nName: %s\nUSN: %s\nBranch: %s\nSemester: %d\nPhone number: %s\n\n",temp->name,temp->usn,temp->branch,temp->sem,temp->phno);
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
    }
}

void del_end() {
    if (start==NULL) {
        printf("List empty\n");
    }
    else {
        struct node *prev, *temp = start;
        while (temp->next!=NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

void del_front() {
    if (start==NULL) {
        printf("List empty\n");
    }
    else {
        struct node *temp = start;
        start = temp->next;
        free(temp);
    }
}

void main()
{
    int ch;
    create_n_nodes();
    printf("Student details:\n");
    display();
    printf("1. display\n2. count no of nodes\n3. insert front\n4. insert end\n5. delete front\n6. delete end\n7. exit\n");
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
            case 7: printf("goodbye\n"); exit(0);
            default: printf("invalid choice\n");
        }
    }
}