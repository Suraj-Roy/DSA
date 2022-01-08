#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void initialisation(struct node **a)
{
    *a=NULL;
}
void sorted_list(struct node **a,int n)
{
    struct node *p,*temp,*c;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    for(p=*a,c=NULL;p && n>p->data;p=p->next)
        c=p;
    temp->next=p;
    if(c)
        c->next=temp;
    else
        *a=temp;
}
void insert(struct node **b,int n){
	struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node)); 
    temp->data=n;
    temp->next=*b;
    *b=temp;
}
void display(struct node *a)
{
	printf("Elements are: ");
    do{
	
        printf("%d ",a->data);
        a=a->next;}while(a!=NULL);
        printf("\n");
}
int main()
{
    int element,n,k,x;
    struct node *a,*b,*c;
    initialisation(&a);
    initialisation(&b);
    printf("Enter choice\n1.insert_sorted\n2.insert_seq\n3.display\n4.exit\n");
    while(1)
    {
    	printf("Enter choice: ");
        scanf("%d",&n);
        switch(n){
        case 1:
        	printf("Enter elements: ");
            scanf("%d",&k);
            sorted_list(&a,k);
            c=a;
            break;
        case 2:
        	printf("Enter elenents: ");
        	scanf("%d",&x);
        	insert(&b,x);
        	c=b;
        	break;
        case 3:
            display(c);
            break;
        case 4:
        	printf("Exiting the program.");
            exit(0);
            break;
        }
    }
    return 0;
} 
