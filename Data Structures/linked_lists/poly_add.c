#include <stdio.h>
#include <stdlib.h>

struct node {
    int cf,px,py,pz,flag;
    struct node *next;
};

struct node *he1, *he2, *he3;

struct node *create() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter cf,px,py,pz: ");
    scanf("%d%d%d%d",&temp->cf,&temp->px,&temp->py,&temp->pz);
    temp->flag = 0;
    temp->next = NULL;
    return temp;
}

void ins_poly1() {
    struct node *temp = create();
    struct node *temp1 = he1;
    while (temp1->next!=he1) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->next = he1;
}

void ins_poly2() {
    struct node *temp = create();
    struct node *temp1 = he2;
    while (temp1->next!=he2) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->next = he2;
}

void ins_poly3(struct node *temp) {
    struct node *temp1 = he3;
    while (temp1->next!=he3) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->next = he3;
}

void create_polys() {
    he1 = (struct node *)malloc(sizeof(struct node));
    he1->next = he1;
    he2 = (struct node *)malloc(sizeof(struct node));
    he2->next = he2;
    he3 = (struct node *)malloc(sizeof(struct node));
    he3->next = he3;
    int n1,n2;
    printf("\nEnter no of terms in poly 1: ");
    scanf("%d",&n1);
    for (int i=0; i<n1; i++) {
        ins_poly1();
    }
    printf("\nEnter no of terms in poly 2: ");
    scanf("%d",&n2);
    for (int i=0; i<n2; i++) {
        ins_poly2();
    }
}

void add() {
    struct node *temp1 = he1;
    struct node *temp2;
    while (temp1->next!=he1) {
        temp1 = temp1->next;
        temp2 = he2;
        while (temp2->next!=he2) {  
            temp2 = temp2->next;
            if (temp2->flag==0 && temp1->px==temp2->px && temp1->py==temp2->py && temp1->pz==temp2->pz) {
                struct node *temp = (struct node *)malloc(sizeof(struct node));
                temp->cf = temp1->cf + temp2->cf;
                temp->px = temp1->px;
                temp->py = temp1->py;
                temp->pz = temp1->pz;
                ins_poly3(temp);
                temp2->flag = 1;
                temp1->flag = 1;
                break;
            }
        }
        if (temp1->flag==0) {
            ins_poly3(temp1);
        }
    }
    struct node *tmp = he2;
    while (tmp->next!=he2) {
        tmp = tmp->next;
        if (tmp->flag==0) {
            ins_poly3(tmp);
        }
    }
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp->next!=head) {
        temp = temp->next;
        printf("%d*x^%dy^%dz^%d + ",temp->cf,temp->px,temp->py,temp->pz);
    }
    printf("0\n");
}

void main()
{
    he1 = he2 = he3 = NULL;
    create_polys();
    printf("Polynomial 1:\n");
    display(he1);
    printf("Polynomial 2:\n");
    display(he2);
    add();
    printf("Resultant polynomial:\n");
    display(he3);
}