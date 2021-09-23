#include<stdio.h>
#include<stdlib.h>
struct stack{
	int *a;
	int sz;
	int top;
};

void push(struct stack *);
void pop(struct stack *);
void display(struct stack *);
int main(){
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	printf("\nenter size of the stack: ");
	scanf("%d",&s->sz);
	
	s->a=(int *)malloc(s->sz*sizeof(int));
	s->top=-1;
	int opt=1;
	do{
		printf("enter \n1 to push\n2 to pop\n3 to display : ");
		scanf("%d",&opt);
		
		switch(opt){
			case 1 : push(s);
			break;
			case 2 : pop(s);
			break;
			case 3 : display(s);
			break;
			case 4 : break;
		}
	}while(opt!=4);
	
	
}void push(struct stack *s){
	if(s->top >= s->sz-1){
		printf("\nthe stack is full ");
		
	}else{
		int ele;
		printf("\nenter the element you wanna passs : ");
		scanf("%d",&ele);
		s->top++;
		s->a[s->top]=ele;
	
	}
}void pop (struct stack *s){
	if(s->top==-1){
		printf("\ncurrently the stack is empty ");
	}else{
		printf("%d element is successfully popped out from the stack",s->a[s->top]);
		s->top--;
		
	}
}void display(struct stack *s){
	int i=0;
	for(i=0;i<=s->top;i++){
		printf(" %d ",s->a[i]);
	}
}
