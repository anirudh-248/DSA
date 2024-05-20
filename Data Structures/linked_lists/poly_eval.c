#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int cf,px,py,pz;
    struct node *next;
};

struct node *head = NULL;
int x,y,z;
float res = 0.0;

struct node *create() {
    if (head==NULL) {
        head = (struct node *)malloc(sizeof(struct node));
        head->next = head;
    }
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter cf,px,py,pz: ");
    scanf("%d%d%d%d",&temp->cf,&temp->px,&temp->py,&temp->pz);
    temp->next = NULL;
    return temp;
}

void ins_end() {
    struct node *temp = create();
    struct node *temp1 = head;
    while (temp1->next!=head) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->next = head;
}

void create_n_terms() {
    int n;
    printf("Enter the no of terms: ");
    scanf("%d",&n);
    if (n>0) {
        for (int i=0; i<n; i++) {
            ins_end();
        }
    }
    else {
        exit(0);
    }
}

void eval() {
    if (head->next==head) {
        printf("List empty\n");
    }
    else {
        printf("Enter x,y,z: ");
        scanf("%d%d%d",&x,&y,&z);
        struct node *temp = head->next;
        while (temp->next!=head) {
            res += (temp->cf*pow(x,temp->px)*pow(y,temp->py)*pow(z,temp->pz));
            temp = temp->next;
        }
        res += (temp->cf*pow(x,temp->px)*pow(y,temp->py)*pow(z,temp->pz));
    }
    printf("Result: %.3f\n",res);
}

void main()
{
    create_n_terms();
    eval();
}