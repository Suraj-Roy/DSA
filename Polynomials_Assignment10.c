#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial{
    int coef,exp;
    struct polynomial *nxt;
}poly;

void initilise(poly **aap){
    *aap=NULL;
}

void insert(poly **aap,int c,int e){
    poly *cur,*prv,*t;
    if(c==0){
        return;
    }

    t=(poly*)malloc(sizeof(poly));
    t->coef=c;
    t->exp=e;

    for(cur=*aap,prv=NULL;cur&&e<cur->exp;cur=cur->nxt){ 

         prv=cur;
    }
   
     if(cur&&e==cur->exp){
        (cur->coef)+=c;
        if(cur->coef==0){
            if(prv){
                prv->nxt=cur->nxt;
            }
            else{
                *aap==cur->nxt;
            }
            free(cur);
        }
        free(t);
        return;
    }
    else
    {
       if(prv){
                prv->nxt=t;
            }
        else
        {
            *aap=t;
        }
        t->nxt=cur;
    }
    
}

void multiplication(poly *ap1,poly *ap2,poly **aar){
    poly *cur;
    initilise(aar);
    for(;ap1;ap1=ap1->nxt){
        for(cur=ap2;cur;cur=cur->nxt){
           

               insert(aar,(ap1->coef)*(cur->coef),(ap1->exp)+(cur->exp));
           
        }
    }
}

void add(poly *ap1,poly *ap2,poly **aar){
    poly *cur,*t1=ap1,*t2=ap2;
    int found;
    initilise(aar);
   
    for(;ap1;ap1=ap1->nxt){
        found=0;
        for(cur=ap2;cur;cur=cur->nxt){
           
              if(ap1->exp==cur->exp){
                found =1;
                  insert(aar,(ap1->coef)+(cur->coef),(ap1->exp));
                  break;
              }
       
        }
        if(!found){
            insert(aar,(ap1->coef),(ap1->exp));
        }
    }
    for(;t2;t2=t2->nxt){
        found=0;
        for(cur=t1;cur;cur=cur->nxt){
            if(t2->exp==cur->exp){
                found=1;
            }
        }
        if(!found){
            insert(aar,(t2->coef),(t2->exp));
        } 
    }
}

void input(poly **aah){
    int c,e;
    char a;
    initilise(aah);
    do{
        printf("enter the coefficient and exponent\n");
        scanf("%d %d",&c,&e);
        insert(aah,c,e);
        printf("do you want to continue?(Y\\N)\n");
        scanf("%s",&a);
       
    }while(a=='y'||a=='Y');
}

void display(poly *ap){
    poly *cur=ap;
    printf("\n\t%dx^%d",cur->coef,cur->exp);
    for(cur=ap->nxt;cur;cur=cur->nxt){
        if(cur->coef==0)
          continue;
        else if(cur->coef>0)
           printf("+%dx^%d",cur->coef,cur->exp);
        else
        {
            printf("%dx^%d",cur->coef,cur->exp);
        }
        
    }
}

int main(){
    int i;
    poly *p1,*p2,*p;
    initilise(&p1);
    initilise(&p2);
    initilise(&p);
    while(1){

    printf("enter choice:\n1.multiplication\n2.add\n3.exit\n");
    scanf("%d",&i);
    switch(i){
        case 1:
             printf("enter first polynomial\n");
             input(&p1);
             printf("enter second polynomial\n");
             input(&p2);
             display(p1);
             printf("\n");
             display(p2);
             printf("\n");
             multiplication(p1,p2,&p);
             display(p);
             printf("\n");
             break;
        case 2:
             printf("enter first polynomial\n");
             input(&p1);
             printf("enter second polynomial\n");
             input(&p2);
             display(p1);
             printf("\n");
             display(p2);
             printf("\n");
             add(p1,p2,&p);
             display(p);
             printf("\n");
             break;
        case 3:
             printf("exiting the program\n");
             exit(0);
        default:
             printf("please enter valid input!!!!\n");
    }
    }
    return 0;
}