#include<stdio.h>
#include<stdlib.h>
 
#define MAX 10
 
struct stack {
   int arr[MAX];
   int top;
};
void init_stk(struct stack *st) {
   st->top = -1;
}
 
void push(struct stack *st, int num) {
   if (st->top == MAX - 1) {
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
 
void display(struct stack *st) {
   int i;
   for (i = st->top; i >= 0; i--){
   
      printf("%d ", st->arr[i]);}
      printf("\n");
}
 
int main() {
   int element, n, val;
   struct stack ptr;
   init_stk(&ptr);
   while (1) {
      printf("1.PUSH,2.pop,3.display,4.Quit\n");
      scanf("%d", &n);
      switch (n) {
      case 1:
         printf("Enter the element into stack:\n");
         scanf("%d", &val);
         push(&ptr, val);
         break;
      case 2:
      element = pop(&ptr);
         printf("The element popped from stack is : %d\n", element);
         break;
      case 3:
         printf("The current stack elements are:\n");
         display(&ptr);
         break;
      case 4:
      	printf("quiting the program");
         exit(0);
         
      default:
         printf("Enter correct option!Try again.\n");
      }
   }
   return (0);
}
