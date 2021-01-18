#include<stdio.h>
#include<stdlib.h>

struct stack {
	int *a;
	int top;
	int sz;
};
int main(){
	
	struct stack *s;
	s=(struct stack*)malloc(sizeof(struct stack));
	printf("enter the size of array\n");
	scanf("%d",&s->sz);
	s->a=(int *)malloc(s->sz*sizeof(int));
	s->top=-1;
	int opt;

	do{
		printf("enter 1.push 2.pop 3.traversal 4.exit\n");
		scanf("%d",&opt);
	 	int i=0;
 		int ele;
		switch(opt){
			
			case 1 :if(s->top>=(s->sz)-1){
						printf("stack is full you cant add elements\n");
					}else{
						s->top++;
						printf("%d is the top  value______________",s->top);
						printf("Enter element : ");
						scanf("%d",&ele);
						s->a[s->top]=ele;
						printf("%d element entered succesfully\n\n",ele);
					}
					break;
			case 2 :if(s->top==-1){
						printf("\nthere are no elements in the stack\n");
					}else{
						printf("%d element removed succesfully\n\n",s->a[s->top]);
						s->top--;
						//pop(s.a[10],s.top);
					}break;
			case 3 :
				for(i=0;i<=s->top;i++){
					printf("%d ",s->a[i]);
					}
					break;
				
			case 4 : exit(0);
				break;
			default:
					printf("invalid entery !!!!\n");
		}
	}while(opt!=4);
}