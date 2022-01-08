#include<stdio.h>
#include<stdlib.h>

typedef struct ll{
    int data;
    struct ll *prv,*next;
}dll;

void intialisation(dll **hd ){
    *hd=NULL;
}

void insertion_sorted(dll **hd,int n){
    dll *prev,*cur,*t;
    t=(dll*)malloc(sizeof(dll));
    t->data=n;
    t->prv=NULL;
    t->next=NULL;
    for(cur=*hd,prev=NULL;cur&&n>cur->data;cur=cur->next){
        prev=cur;
    }
     t->next=cur;
    if(cur)
      cur->prv=t;
    
    if(prev){
        prev->next=t;
        t->prv=prev;
    }
    else
    {
        *hd=t;
        
    }
    
}

void insertion_seq(dll **hd,int n){
    dll *prev,*cur,*t;
    t=(dll*)malloc(sizeof(dll));
    t->data=n;
    t->prv=NULL;
    t->next=NULL;
    for(cur=*hd,prev=NULL;cur;cur=cur->next){
        prev=cur;
    }
    t->next=cur;
    if(cur)
      cur->prv=t;
    
    if(prev){
        prev->next=t;
        t->prv=prev;
    }
    else
    {
        *hd=t;
        
    }
    
}

void deletion(dll **hd,int n){
    dll *prev,*cur;
    int found=0;
    for(cur=*hd,prev=NULL;cur;cur=cur->next){
    if(cur->data==n){
        found=1;
        if(prev){
            prev->next=cur->next;
            if(cur->next){
                
             (cur->next)->prv=prev;
            }
        }
        else
        {
            *hd=cur->next;
            if(cur->next){
              (cur->next)->prv=NULL;
            }
        }
        free(cur);
        printf("%d is deleted sucessfully\n",n);
        return;
        }
        else
        {
            prev=cur;
        }
    }
        if(!found){
            printf("element not found in the list\n");
        }
        
        
    }


void display(dll *hd){
    dll *cur;
    if(hd==NULL){
     printf("empty list\n");
     return;
    }
    for(cur=hd;cur;cur=cur->next){
        printf("%d ",cur->data);
    }
}

void display_reverse(dll *hd){
    dll *cur;
    if(hd==NULL){
     printf("empty list\n");
     return;
    }
    for(cur=hd;cur->next;cur=cur->next);
    while(cur){
        printf("%d ",cur->data);
        cur=cur->prv;
    }
}

int main(){
	int x,y;
	dll *hds,*hd,*d;
	intialisation(&hds);
    intialisation(&hd);
    intialisation(&d);
	printf("enter choice:\n1.insertion sorted\n2.insertion sequential\n3deletion\n4.display\n5.display reverse\n6.exit\n");
	
	while(1){
		printf("Enter choice: ");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("Enter number: ");

				scanf("%d",&y);
				insertion_sorted(&hds,y);
                d=hds;
				break;
			
			case 2:
				printf("Enter number: ");

				scanf("%d",&y);
				insertion_seq(&hd,y);
                d=hd;
				break;
			case 3:
				printf("Enter number to be deleted: ");

				scanf("%d",&y);
				deletion(&d,y);
				break;
		    case 4:
		    	printf("elements are: ");
                display(d);
                printf("\n");
                break;
            case 5:
                printf("elements in reverseorder are: ");
                display_reverse(d);
                printf("\n");
                break;
			case 6:
				printf("exiting the program.");
				exit(0);
			default:
				printf("please enter a valid choice!!\n");
		}
	}
	return 0;
}




