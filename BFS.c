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
 int front, rear;
 int *vertex;
}QUEUE;




void input_graph(GRAPH *);

void initialisation_queue(QUEUE *, int );

void insert_q(QUEUE *, int );

int delete_q(QUEUE *);

void BFS(GRAPH , int);

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
         for( j = 0; j < n; j++)
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


void initialisation_queue(QUEUE *q, int queue_size)
{
    q->front=-1;
    q->rear=-1;
    q->vertex=(int *)malloc(sizeof(int)*queue_size);
}


void insert_q(QUEUE *q, int v)
{
    q->vertex[++(q->rear)]=v;
}



int delete_q(QUEUE *q)
{
    if(q->front==q->rear)
    {
       printf("\n Empty queue...");
       q->front=-1;
       q->rear=-1;
       exit(0);
    }
    else
       return q->vertex[++(q->front)];
}




void BFS(GRAPH G, int v)
{
 QUEUE queue;
 int *visited;
 int i, p;
 printf("\n");
 initialisation_queue(&queue, G.n); /* Queue Initialisation */
 visited=(int *)malloc(sizeof(int)*G.n);
 for(i=0; i<G.n; i++) /* Mark all the node as unvisited. */
         visited[i]=0;
 visited[v]=1; /* Mark the Starting node as visited. */
 insert_q(&queue, v); /* Insert the starting vertex in Queue.*/
 while(queue.front != queue.rear)
/*Continue until Queue is not empty. */
 {
     p=delete_q(&queue);
   //p : the current node just remove from the Queue./
     printf("Visited %c  ", G.V[p]);
     //printf("\n %d %d", queue.front, queue.rear);
/*Insert those nodes into Queue which are adjacent to p and not visited earlier. */
     for (i=0; i<G.n; i++)
        if(G.wt[p][i]!=0 && visited[i]==0)
          {
             insert_q(&queue,i);
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

   BFS(G, c-'A');

   free_graph(&G);
}
