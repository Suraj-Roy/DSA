#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}csll;

void initiliasition(csll **aah){
    *aah=NULL;
}

void insertion_sorted(csll **aah,int n){
    csll *cur,*prv=NULL,*last,*t;
    cur=*aah;
    t=(csll*)malloc(sizeof(csll));
    t->data=n;
     if(*aah==NULL){
        *aah=t;
        t->next=t;
        
    }
    else if(n<(*aah)->data){
         for(last=*aah;last->next!=*aah;last=last->next);
             last->next=t;
             t->next=*aah;
             *aah=t;
     } 
    else{
        while(n>cur->data){
            prv=cur;
            cur=cur->next;
            if(cur==*aah){
                break;
            }
        }
        t->next=cur;
        prv->next=t;
    }   
     }

void insert(csll **aah,int n){
    csll *cur,*t;
    t=(csll*)malloc(sizeof(csll));
    t->data=n;
    if(*aah==NULL){
        *aah=t;
        t->next=t;
        return;
    }
    for(cur=*aah;cur->next!=*aah;cur=cur->next);
    cur->next=t;
    t->next=*aah;
}

void display(csll *aah){
    csll *cur;
    cur=aah;
    if(aah==NULL){
        printf("list is empty\n");
        return;
    }
do{
    printf("%d ",cur->data);
    cur=cur->next;
}while(aah!=cur);
    
}

 
void deletion(csll **aah,int n){
    csll *cur,*prv=NULL,*last,*temp=NULL;
    cur=*aah;
    int found=0;
    
     if(*aah==NULL){
        printf("list is empty\n");
        return;
    }
    while(temp!=cur){
        if(cur->data==n){
            found=1;
            break;
        }
        temp=*aah;
        cur=cur->next;
        
    }
    if(found){
        cur=*aah;

    if(n==(*aah)->data&&*aah==cur->next){
        *aah=NULL;
    }
    else if(n==(*aah)->data){
        for(last=*aah;last->next!=*aah;last=last->next);
        *aah=cur->next;
        last->next=*aah;
    }
    else{
         while(n!=cur->data){
            prv=cur;
            cur=cur->next;
            if(cur==*aah){
                break;
            }
        }
        
        prv->next=cur->next;
    }   
    
            free(cur);
             printf("%d id deleted\n",n);
             return;
    
     }
     else{

          printf("element not found\n");
        }
        
    
}

int main(){
    int x,y;
    csll *a,*b,*c;
    initiliasition(&a);
    initiliasition(&b);
    initiliasition(&c);
    printf("enter choice\n1.insertion sorted\n2.insertion sequential\n3.display\n4.deleton\n5.exit\n");
    while(1){
        printf("enter choice: ");
        scanf("%d",&x);
        switch(x){
            case 1:
              printf("enter elements: ");
              scanf("%d",&y);
              insertion_sorted(&a,y);
              c=a;
              break;
            case 2:
              printf("enter elements: ");
              scanf("%d",&y);
              insert(&b,y);
              c=b;
              break;
            case 3:
             printf("elements are: ");
             display(c);
             printf("\n");
             break;
            case 4:
              printf("enter elements to be deleted: ");
              scanf("%d",&y);
              deletion(&c,y);
              break;
            case 5:
              printf("Exiting the program\n");
              exit(0);
            default:
               printf("please enter a valid choice\n");
        }
    }
    return 0;

}