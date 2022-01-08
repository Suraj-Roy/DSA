#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 

typedef struct 
{
 int *C;
 int no_rook;
}BOARD;



void initialisation(BOARD *B, int n)
{
  int i;
  B->no_rook=n;
  B->C=(int*)malloc(sizeof(int)*(n+1));
  for(i=1;i<=n;i++)
       B->C[i]=-1;
}

void display_board(BOARD B, int n, int *a_sol_no)

{
  int i,j;
  printf("\n\n Solution %d ", ++(*a_sol_no));
  for(i=1;i<=n;i++)
  {
     printf("\n");
     for(j=1;j<=n;j++)
        if(B.C[i]==j)
          printf(" H"); 
        else
          printf(" *");
   }  
}

int is_safe(BOARD B, int x, int y)
{
  int i;
  for(i=1;i<x;i++)
      if (B.C[i]==y)
            return 0;
  return 1; 
}

void n_rook(BOARD *B, int k, int n, int *a_sol_no)

{
  int j;
  for(j=1;j<=n;j++)
        if(is_safe(*B, k, j)) 
          {
              B->C[k]=j;
             if(k==n) 
                   display_board(*B, n, a_sol_no); 
             else
                   n_rook(B,k+1,n, a_sol_no); 
          } 
}


 
void main( )
{
  int n;
 BOARD *p;
 int sol_no=0;
 p=(BOARD *)malloc(sizeof(BOARD));
 printf("enter no of rooks: ");
 scanf("%d",&n);
 initialisation(p,n);
  n_rook(p,1,n,&sol_no);
}