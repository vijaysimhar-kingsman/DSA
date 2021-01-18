#include<stdio.h>
#include<stdlib.h>

struct stack{
	char *a;
	int top;
	int sz;
};
void push(struct stack *s,char x){
	if(s->top==(s->sz)-1){
		printf("stack is full");
	}else{
		s->top++;
		s->a[s->top]=x;
	}
}char pop(struct stack *s){
	if(s->top==-1){
		printf("stack is empty");
	}else{
		//return s->a[s->top];
		s->top--;
	}
}int top(struct stack *s){
	printf("%d",s->top);
	return s->top;
}int isempty(struct stack *s){
	if(s->top<=-1){
		return 1;
	}else{
		return 0;
	}
}

/**int prior(char c){
	if(c=='('){
		return 0;
	}else if(c=='+'||c=='-'){
		return 1;
	}else if(c=='*'||c=='/'){
		return 2;
	}else{
		return 3;
	}
}**/
void prin(struct stack *s){
	
	int i;
	for(i=0;i<=s->top;i++){
		printf("%c",s->a[i]);
	}
}


int main(){

	
	struct stack *s;
	s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	s->sz=20;
	s->a=(char *)malloc(s->sz*sizeof(char));
	printf("enter some value and then ask.............");
	push(s,'a');top(s);
	pop(s);	top(s);
	push(s,'b');top(s);
	push(s,'d');top(s);
	push(s,'c');top(s);
	pop(s);top(s);prin(s);
}
