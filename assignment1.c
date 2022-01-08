#include<stdio.h>
#include<stdlib.h>
int main(){
	int arr[10],pos,val, i,j,k;
	int size;
	printf("enter the size of array: ");
	scanf("%d",&size);
	printf("enter array elements: \n");
	for(i=0;i<size;i++){
 	scanf("%d",&arr[i]);}
 	printf("enter 0 for deleting and 1 for inserting:\n");
 	scanf("%d",&k);
 		
 	if(k){
 		if(size==10){
 			printf("overflow");
 			exit(1);
		 }
		 else{
		 
 		printf("enter position and value :\n");
 		scanf("%d%d",&pos,&val);
 	  for (j = size-1; j >= pos - 1; j--){
	  
      arr[j+1] = arr[j];}
 
   arr[pos-1] = val;
   size++;}
	 }
	 else{
	 	printf("enter the pos: ");
	 	scanf("%d",&pos);
	 	 for(i=pos-1; i<size-1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
	 }
	 printf("the resultant array is:\n");
	 for(i=0; i<size; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
 
}
