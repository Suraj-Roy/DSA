#include<stdio.h>
#include<stdlib.h>
 
#define MAXSTK 10
 
struct stack {
   int *arr;
   int top;
};
void init_stk(struct stack *st) {
	st->arr=(int*)malloc(sizeof(int)*MAXSTK);
   st->top = -1;
}
 
void push(struct stack *st, int num) {
   if (st->top == MAXSTK - 1) {
      printf("Stack overflow\n");
   }
   else{
   
   st->top++;
   st->arr[st->top] = num;}
}

int pop(struct stack *st) {
   int num;
   if (st->top == -1) {
      printf("Stack underflow.\n");
      return NULL;
   }
   num = st->arr[st->top];
   st->top--;
   return num;
}
void full(struct stack *st){
	if(st->top==MAXSTK-1){
		printf("stack is full\n");
	}
	else{
		printf("stack is empty\n");
	}
}
int main() {
   int element, n, val;
   struct stack ptr;
   init_stk(&ptr);
   while (1) {
      printf("0.PUSH,1.pop,2.Quit,3.stack is empty or full\n");
      scanf("%d", &n);
      switch (n) {
      case 0:
         printf("Enter the element into stack:\n");
         scanf("%d", &val);
         push(&ptr, val);
         break;
      case 1:
         element = pop(&ptr);
         printf("The element popped from stack is : %d\n", element);
         break;
      case 2:
      	printf("quiting the program");
         exit(0);
      case 3:
	     full(&ptr);
		 break;  
      default:
         printf("Enter correct option!Try again.\n");
      }
   }
   return (0);
}
