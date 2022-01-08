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

void insert_it(bstree **aar,int n){
	bstree *temp,*par,*cur;
	temp=(bstree*)malloc(sizeof(bstree));
	temp->data=n;
	temp->left=temp->right=NULL;
	if(*aar==NULL){
		*aar=temp;
	}
	else{
		par=NULL;
		cur=*aar;
		while(cur!=NULL){
			par=cur;
			if(n<=cur->data){
				cur=cur->left;
			}
			else{
				cur=cur->right;
			}
		}
		if(n<par->data){
			par->left=temp;
		}
		else{
			par->right=temp;
		}
	}
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
int main(){
	int x,y,k;
	bstree *ar;
	initilisation(&ar);
	printf("enter choice:\n1.insertion recursive\n2.insertion iterative\n.3.preorder recursive\n4.inorder\n5.postorder\n6.exit\n");
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
				printf("Enter number: ");
				scanf("%d",&y);
				insert_it(&ar,y);
				break;
			case 3:
				printf("elements preorderwise are:\n");
				preorder(ar);
				printf("\n");
				break;
			case 4:
				printf("elements inorderwise are:\n");
				inorder(ar);
				printf("\n");
				break;
			case 5:
				printf("elements postorderwise are:\n");
				postorder(ar);
				printf("\n");
				break;
			case 6:
				printf("exiting the program.");
				exit(0);
		}
	}
}
