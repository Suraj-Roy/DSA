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

void preorder(bstree *aar){
	if(aar){
		printf("%d ",aar->data);
		preorder(aar->left);
		preorder(aar->right);
	}
}

void inorder(bstree *aar){
	if(aar){
		preorder(aar->left);
		printf("%d ",aar->data);
		preorder(aar->right);
	}
}

void postorder(bstree *aar){
	if(aar){
	
		postorder(aar->left);
		postorder(aar->right);
		printf("%d ",aar->data);
	}
}
void dispTree(bstree *ar, int n)
{
    if(ar==NULL)
        return;
    else
    {
        dispTree(ar->right,n+5);
        for(int i=0; i<n; i++)
            printf(" ");
        printf("%d\n",ar->data);
        dispTree(ar->left,n+5);
    }
}

int max(int x,int y){
	if(x>y){
		return x;
	}
	else
	   return y;
}

int height(bstree *aar){
	if(aar==NULL){
		return 0;
	}
	else 
	return (1+max(height(aar->left),height(aar->right)));
}


void mirror(bstree **aar){
	bstree *t;
	if(*aar!=NULL){
		mirror(&(*aar)->left);
		mirror(&(*aar)->right);
		t=(*aar)->left;
		(*aar)->left=(*aar)->right;
		(*aar)->right=t;
	}
}

int totalnodes(bstree *t){
	if(t==NULL){
		return 0;
	}
	return (totalnodes(t->left)+totalnodes(t->right)+1);
}

int leaf_nodes(bstree *t){
	if(t==NULL){
		return 0;
	}
	else if(t->left==NULL&&t->right==NULL)
        return 1;
	else{
		return leaf_nodes(t->left)+leaf_nodes(t->right);
	}
}

int internal_nodes(bstree *t){
 if((t==NULL)||(t->left==NULL&&t->right==NULL))
   return 0;
 else
  return(internal_nodes(t->left)+internal_nodes(t->right)+1);
}

 void find_largest(bstree *t){
    while(t->right!=NULL){
    	t=t->right;
	}
	printf("the largest element is: %d\n",t->data);
}

void find_smallest(bstree *t){
 while(t->left!=NULL){
    	t=t->left;
	}
	printf("the samllest element: %d",t->data);
}

void freespace(bstree **aar){
	if(*aar==NULL){
		freespace(&(*aar)->left);
		freespace(&(*aar)->right);
		freespace(aar);
	}
}
int main(){
	int x,y,k;
	bstree *ar,*a;
	initilisation(&ar);
	printf("enter choice:\n1.insertion recursive\n2.preorder recursive\n3.inorder\n4.postorder\n");
	printf("5.height\n6.totalnodes\n7.totalleafnode\n8.total intrenal nodes\n9.maximum\n10.minimum\n11.mirror\n12.freememory\n13.exit\n");
	while(1){
		printf("Enter choice: ");
		scanf("%d",&x);
		switch(x){
			case 1:
				printf("Enter number: ");
				scanf("%d",&y);
				insert_rc(&ar,y);
				break;
			
			case 2:
				printf("elements preorderwise are:\n");
				preorder(ar);
				printf("\n");
				break;
			case 3:
				printf("elements inorderwise are:\n");
				inorder(ar);
				printf("\n");
				break;
			case 4:
				printf("elements postorderwise are:\n");
				postorder(ar);
				printf("\n");
				break;
			case 5:
				printf("height is: %d\n",height(ar));
				break;
			
			case 6:
				printf("totalnones are: %d\n",totalnodes(ar));
				break;
			case 7:
				printf("leaf_nodes are: %d\n",leaf_nodes(ar));
				break;
			case 8:
				printf("internal_nodes are: %d\n",internal_nodes(ar));
				break;
			case 9:
				find_largest(ar);
				break;
			case 10:
				find_smallest(ar);
				break;

			case 11:
				printf("Original Tree:\n");
                    dispTree(ar,5);
                    mirror(&ar);
                    printf("\nMirrored Tree\n");
                    dispTree(ar,5);
                    printf("\n");
				break;
			case 12:
				freespace(&ar);
				printf("memory deallocated\n");
				break;
			case 13:
				printf("exiting the program.");
				exit(0);
		}
	}
}

