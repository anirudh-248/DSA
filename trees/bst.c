#include <stdio.h>
#include <stdlib.h>

struct bst {
    int data;
    struct bst *left, *right;
};

typedef struct bst node;
node *root = NULL;

node *create() {
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("Enter the data item: ");
    scanf("%d",&temp->data);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert() {
    node *temp = create();
    if (root==NULL) {
        root = temp;
    }
    else {
        node *temp1 = root;
        while (temp1!=NULL) {
            if (temp->data < temp1->data) {
                if (temp1->left==NULL) {
                    temp1->left = temp;
                    break;
                }
                temp1 = temp1->left;
            }
            else {
                if (temp1->right==NULL) {
                    temp1->right = temp;
                    break;
                }
                temp1 = temp1->right;
            }
        }
    }
    printf("item %d inserted\n",temp->data);
}

void display(node *temp) {
    if (root==NULL) {
        printf("tree empty\n");
        return;
    }
    if (temp==NULL) {
        return;
    }
    display(temp->left);
    printf("%d\t",temp->data);
    display(temp->right);
}

void main() {
    int ch;
    printf("1.insert  2.display  3.exit\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1: insert(); break;
            case 2: display(root); printf("\n"); break;
            case 3: printf("goodbye\n"); exit(0);
            default: printf("invalid choice");
        }
    }
}