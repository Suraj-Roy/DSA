#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 

typedef struct 
{
 int *C;
 int no_bishop;
}BOARD;



void initialisation(BOARD *B, int n)
{
  int i;
  B->no_bishop=n;
  B->C=(int*)malloc(sizeof(int)*(n+1));
  for(i=1;i<=n;i++)
       B->C[i]=-1;
}

void display_board(BOARD B, int n, int *a_sol_no)

{
  int i,j;
  
  printf("\n\n Solution %d \n", ++(*a_sol_no));
  for(i=1;i<=n;i++)
  {
     printf("\n");
     for(j=1;j<=n;j++)
        if(B.C[i]==j)
          printf(" B"); 
        else
          printf(" *");
   }  

   printf("\n\n Solution %d \n", ++(*a_sol_no));
  for(i=1;i<=n;i++)
  {
     printf("\n");
     for(j=1;j<=n;j++)
        if(B.C[j]==i)
          printf(" B"); 
        else
          printf(" *");
   }  
}

int is_safe(BOARD B, int x, int y)
{
  int i;
  for(i=1;i<x;i++)
      if (abs(x-i)==abs(y-B.C[i]))  
            return 0;
  return 1; 
}

void n_bishop(BOARD *B, int k, int n, int *a_sol_no)

{
  int j;
  for(j=1;j<=n;j++)
        if(is_safe(*B, k, j)) 
          {
              B->C[k]=j;
             if(k==n) 
                   display_board(*B, n, a_sol_no); 
             else
                   n_bishop(B,k+1,n, a_sol_no); 
          } 
}


 
void main( )
{
  int n;
 BOARD *p;
 int sol_no=0;
 p=(BOARD *)malloc(sizeof(BOARD));
 printf("enter no of bishop: ");
 scanf("%d",&n);
 initialisation(p,n);
  n_bishop(p,1,n,&sol_no);
}