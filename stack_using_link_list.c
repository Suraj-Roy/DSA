#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head;

void push(int x){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=head;
	head=temp;
}

void pop(){
  struct node *temp;
  if(head==NULL){
  	printf("stack underflow\n");
  }	
  else{
  	temp=head;
  	printf("pop out element is: %d\n",temp->data);
  	head=temp->next;
  	temp->next=NULL;
  	free(temp);
  }
}

void display(){
    struct node *temp;
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");	
}
int main(){
	int capacity,count=0,n,m;
	printf("Enter capacity of stack: ");
	scanf("%d",&capacity);
	printf("\nENTER choice\n1.push\n2.pop\n3.display\n4.quit\n\n");
	while(1){
		printf("Enter choice: ");
		scanf("%d",&n);
		switch(n){
			case 1:
				if(count<capacity){
				printf("Enter number: ");
				scanf("%d",&m);
				push(m);
				count++;
				}
				else{
					printf("stack overflow\n");
				}
				break;
			case 2:
				pop();
				break;
			case 3:
				printf("Elements in stack are: ");
				display();
				break;
			case 4:
				printf("quiting the program\n");
				exit(1);
				break;
			default:
                printf("Enter correct option!Try again.\n");
		}
	}
	return 0;
}
