#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void initilisation(struct node **a){
	*a=NULL;
}

void insert(struct node **a,int n){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->next=*a;
	*a=temp;
}

void recursive_display(struct node *a){
	if(a==NULL){
		printf("\n");
		return;
	}
	printf("%d ",a->data);
	recursive_display(a->next);
}

void count(struct node *a){
	int count=0;
	struct node *c;
	c=a;
	while(c!=NULL){
		count++;
		c=c->next;
	}
	printf("total number of elements are: %d\n",count);
} 

void deletion(struct node **a,int n){
	struct node *cur,*prv;
	int found=0;
	for(cur=*a,prv=NULL;cur;cur=cur->next){
		if(prv!=NULL && n==cur->data){
			found=1;
			prv->next=cur->next;
			free(cur);
			return;
		}
		else if(prv==NULL && n==cur->data){
			*a==cur->next;
			free(cur);
			found=1;
			return;
		}
		else{
			prv=cur;
		}
		
	}
	if(!found){
		printf("data is not in the list\n");
	}
}

void rev(struct node **a){
	struct node *temp,*cur,*prv;
	for(cur=*a,prv=NULL;cur;cur=temp){
		temp=cur->next;
		cur->next=prv;
		prv=cur;
	}
	*a=prv;
}

int main(){
	struct node *a;
	int x,y,d;
	initilisation(&a);
	printf("Enter coice:\n1.insertion\n2.display\n3.count\n4.reverse linked list\n5.delete\n6.exit\n");
	while(1){
		printf("Enter choice: ");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("Enter number: ");
				scanf("%d",&y);
				insert(&a,y);
				break;
			case 2:
				recursive_display(a);
				break;
			case 3:
				count(a);
				break;
			case 4:
				rev(&a);
				break;
			case 5:
				printf("Enter element to be deleted: ");
				scanf("%d",&d);
				deletion(&a,d);
				break;
			case 6:
				printf("Exiting the program");
				exit(0);
				
		}
	}
}


