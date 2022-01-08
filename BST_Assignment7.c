#include<stdio.h>
#include<stdlib.h>
typedef struct btree{
	int data;
	struct btree *left,*right;
}bstree;

void initilisation(bstree **aar){
	*aar=NULL;
}

void insert_rc(bstree **aar,int n){
	if(*aar==NULL){
		*aar=(bstree*)malloc(sizeof(bstree));
		(*aar)->data=n;
		(*aar)->left=(*aar)->right=NULL;
	}
	else if(n<(*aar)->data)
	     insert_rc(&((*aar)->left),n);
    else
        insert_rc(&((*aar)->right),n);
}

void preorder(bstree *aar,int MAX){
    int top=-1;
    bstree *stk[MAX];
    while(1){
    	while(aar){
    		printf("%d ",aar->data);
    		if(top==MAX-1){
    			printf("overflow\n");
    			exit(0);
			}
			stk[++top]=aar;
			aar=aar->left;
		}
		if(top!=-1){
			aar=stk[top--];
			aar=aar->right;
		}
		else
		 break;
	}
    
}

void inorder(bstree *aar,int MAX){
    int top=-1;
    bstree *stk[MAX],*t;
    while(1){
    	while(aar){
    		if(top==MAX-1){
    			printf("overflow\n");
    			exit(0);
			}
			stk[++top]=aar;
			aar=aar->left;
		}
		if(top!=-1){
			aar=stk[top--];
			printf("%d ",aar->data);
			aar=aar->right;
		}
		else
		 break;
	}
    
}
void search(bstree **aar,bstree **x,bstree **par,int *found,int n){
	bstree *q=*aar;
	*par=NULL;
	*found=0;
	while(q!=NULL){
		if(n==q->data){
			*x=q;
			*found=1;
			return;
		}
		else if(n<q->data){
			*par=q;
			q=q->left;
		}
		else{
			*par=q;
			q=q->right;
		}
	}
}

int deletion(bstree **aar,int n){
	int found=0;
	bstree *x,*par,*ios;
	if(*aar==NULL){
		printf("empty tree\n");
		return found;
	}
	x=par=NULL;
	search(aar,&x,&par,&found,n);
	if(found==0){
		return found;
	}
	
	if(x->left!=NULL&&x->right!=NULL){
		par=x;
		ios=x->right;
	
	while(ios->left!=NULL){
		par=ios;
		ios=ios->left;
	}
	x->data=ios->data;
	x=ios;
   }
	if(x->left==NULL&&x->right==NULL){
		if(x==*aar)
		  *aar=NULL;
		else if(par->left==x)
		  par->left=NULL;
		else
		  par->right=NULL;
		free(x);
		return found;
	}
	
	if(x->left!=NULL&&x->right==NULL){
		if(x==*aar)
		  *aar=(*aar)->left;
		else if(par->left==x)
		  par->left=x->left;
		else
		  par->right=x->left;
		free(x);
		return found;
	}	
	
	if(x->left==NULL&&x->right!=NULL){
		if(x==*aar)
		  *aar=(*aar)->right;
		else if(par->left==x)
		  par->left=x->right;
		else
		  par->right=x->right;
		free(x);
		return found;
	}
	
}
void display(bstree *ar, int n)
{
    if(ar==NULL)
        return;
    else
    {
        display(ar->right,n+5);
        for(int i=0; i<n; i++)
            printf(" ");
        printf("%d\n",ar->data);
        display(ar->left,n+5);
    }
}


int main(){
	int x,y,k,j;
	k=0;
	bstree *ar;
	initilisation(&ar);
	printf("enter choice:\n1.insertion\n2.preorder\n3inorder\n4.deletion\n5.display\n6.exit\n");
	
	while(1){
		printf("Enter choice: ");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("Enter number: ");
				k++;
				scanf("%d",&y);
				insert_rc(&ar,y);
				break;
			
			case 2:
				printf("elements preorderwise are:\n");
				preorder(ar,k);
				printf("\n");
				break;
			case 3:
				printf("elements inorderwise are:\n");
				inorder(ar,k);
				printf("\n");
				break;
		    case 4:
		    	printf("Enter number to be deleted: ");
		    	scanf("%d",&y);
		        j=deletion(&ar,y);
		        if(j==0){
		        	printf("number not found\n");
				}
				else{
				  printf("%d is deleted sucessfully\n",y);
				  k--;}
		    	break;
		    case 5:
		    	display(ar,5);
		    	break;
			case 6:
				printf("exiting the program.");
				exit(0);
			default:
				printf("please input valid number!!\n");
		}
	}
	return 0;
}


