#include<stdio.h>
#include<stdlib.h>


typedef struct
{
   int n;
   char *V;
   int **wt;
}GRAPH;

typedef struct
{
   int top;
   int *vertex;
}STACK;




void input_graph(GRAPH *);
void initialisation_stack(STACK *, int);

void push(STACK *, int );

int pop(STACK *);

void DFS(GRAPH , int);

void free_graph (GRAPH *);

void input_graph(GRAPH *aG)
{
   int i,j,n;
   char ans;
   printf("\n Enter the no. of vertices :");
   scanf("%d",&aG->n);
   
   aG->V=(char *)malloc(sizeof(char)*aG->n);
   for(i=0;i<aG->n;i++)
      aG->V[i]='A'+i;
   aG->wt=(int**)malloc(sizeof(int)*aG->n);
   for(i=0;i<aG->n;i++)
      {
         aG->wt[i]=(int*)malloc(sizeof(int)*aG->n);
      }
   
   for(i=0;i<aG->n;i++)
   {
      for(j=0;j<aG->n;j++){
         aG->wt[i][j]=0;}
   }
   for(i = 0; i < aG->n; i++)
      {
         printf("\nEnter number of vertices adjacent to %c : ",'A'+i);
         scanf("%d",&n);
         char v;

         printf("\nEnter the Vertices  adjacent to %c : \n",'A'+i);
         for(j = 0; j < n; j++)
         {
            scanf(" %c",&v);
            int k=v-'A';
            if( k< aG->n)
               aG->wt[i][k] = 1;
            else
            {
               printf("Invalid edge\n");
               printf("\nPlease enter lastly entered Vertex adjacent to %c correctly: \n",'A'+i);
               j--;
            }
         }

      }



 }


void initialisation_stack(STACK *s, int stack_size)
{
   s->top=-1;
   s->vertex=(int *)malloc(sizeof(int)*stack_size);
}



void push(STACK *s, int v)
{
    s->vertex[++(s->top)]=v;
}



int pop(STACK *s)
{
   if(s->top==-1)
   {
      printf("\n Empty stack...");
      exit(0);
   }
   return s->vertex[(s->top)--];
}




void DFS(GRAPH G, int v)
{
   STACK stk;
   int *visited;
   int i, p;
   printf("\n");
   initialisation_stack(&stk, G.n); /* Stack Initialisation */
   visited = (int *)malloc(sizeof(int)*G.n);
   for(i=0;i<G.n;i++) /* Mark all the node as unvisited. */
            visited[i]=0;
   visited[v]=1;  /* Mark the Starting node as visited. */
   push(&stk,v); /* Insert the starting vertex in Stack.*/
   while(stk.top!=-1)  /*Continue until Stack is not empty. */
   {
      p=pop(&stk); //p : the current node just remove from the Stack./
      printf("Visited %c  ", G.V[p]);
   /*Insert those nodes into Stack which are adjacent to p and not visited earlier. */
      for (i=0; i<G.n; i++)
         if(G.wt[p][i]!=0  && visited[i]==0)
            {
               push(&stk, i);
               visited[i]=1;
            }
   }
   free(visited);
   printf("\n");
}





void free_graph (GRAPH *G)
{
   int i,j;

   free(G->V);
   for(i=0; i<G->n; i++)
      free(G->wt[i]);
   free(G->wt);
}


void main()
{
   GRAPH G;
   char c;
   input_graph(&G);
   printf("Enter the vertex you want to start with:");
   scanf(" %c",&c);

   DFS(G, c-'A');

   free_graph(&G);
}