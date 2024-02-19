#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 100
struct bst {
    char info;
    struct bst *left, *right;
};
typedef struct bst node;

node *create(char post[]) {
    node *new1, *stk[max];
    int top=-1;
    char sym;
    for (int i=0; post[i]!='\0'; i++) {
        sym = post[i];
        new1 = (node*)malloc(sizeof(node));
        new1->info = sym;
        new1->left = new1->right = NULL;
        if (isalnum(sym)) {
            stk[++top] = new1;
        }
        else {
            new1->right = stk[top--];
            new1->left = stk[top--];
            stk[++top] = new1;
        }
    }
    return stk[top--];
}

float eval(node *root) {
    float num;
    switch (root->info) {
        case '+': return (eval(root->left) + eval(root->right)); break;
        case '-': return (eval(root->left) - eval(root->right)); break;
        case '*': return (eval(root->left) * eval(root->right)); break;
        case '/': return (eval(root->left) / eval(root->right)); break;
        default:
            if (isalpha(root->info)) {
                printf("%c",root->info);
                scanf("%f",&num);
            }
            else num = root->info - '0';
            return num;
    }
}

void main()
{
    char post[max];
    float res;
    node *root = NULL;
    printf("Enter postfix exp: ");
    scanf("%s",post);
    root = create(post);
    res = eval(root);
    printf("Result: %.3f\n",res);
}