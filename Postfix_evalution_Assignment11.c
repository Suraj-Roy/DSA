#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100

typedef struct node{
    float data;
    struct node *next;
} stack;

void initilisation(stack **head){
    *head=NULL;
}

void push(float n,stack **head) {
    stack *t;
    t=(stack*)malloc(sizeof(stack));
    t->data=n;
    t->next=*head;
    *head=t;
    
}

float pop(stack **head) {
    stack *tNode;
    tNode = *head;
    *head = (*head)->next;
    return tNode->data;
}


int main() {
    int i = 0; 
    float no1,no2;
    char exp[MAX];
    
    char tmp;
    stack *head;
    initilisation(&head);

    printf("Enter the postfix expression: ");
    scanf(" %s", exp);

    while( (tmp=exp[i++]) != '\0') {   
        if(tmp >= '0' && tmp <= '9') {
            int no = tmp - '0';
            push(no,&head);
            continue;
        }

        if(tmp == '+') {
             no1 = pop(&head);
             no2 = pop(&head);
            push((no2 + no1),&head);
        } else if (tmp == '-') {
             no1 = pop(&head);
             no2 = pop(&head);
            push((no2 - no1),&head);
        } else if (tmp == '*') {
             no1 = pop(&head);
             no2 = pop(&head);
            push((no2 * no1),&head);
        } else if (tmp == '/') {
             no1 = pop(&head);
             no2 = pop(&head);
            push((no2 / no1),&head);
        }
       else if (tmp == '^') {
            no1 = pop(&head);
            no2 = pop(&head);
            push(pow(no2,no1),&head);
        }
    }

    printf("Result of the evalution is %.2f", pop(&head));
    return 0;
}
