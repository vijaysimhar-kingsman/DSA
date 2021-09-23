#include<stdio.h>
struct stack{
	int a[10];
	int top;
	int size;
};
void allout(struct stack *s,int a[],int b[]){
	if((s->a[s->top])!= a[5]){
		pop(s);
		allout(s,a,b);
	}pop(s);
}
void priority(char x,char y,struct stack * s,int a[],int b[]){
	int i,j;
	for(i=0;i<=6;i++){
		if(a[i]==x){
			break;
		}		  
	}
	for(j=0;j<=6;j++){
		if(a[j]==y){
			break;
		}		
	}if(b[i]==5){
		allout(s,a,b);
		priority(x,s->a[s->top],s,a,b);
	}else if(b[i]>b[j]){
		push(x,s);
	}else{
		pop(s);
		if(s->top!=-1){
			priority(x,s->a[s->top],s,a,b);
		}else{
			push(x,s);
		}
		
	}
}
void pop(struct stack *s){
	printf(" %c ",s->a[s->top]);
	s->top--;
}
void push (char str,struct stack *s){
	if(s->top >= (s->size-1))
		printf("stack is full________");
	else{
		s->top++;
		s->a[s->top]=str;
	}
	
}

int main(){
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->top=-1;
	s->size=10;
	char a[]={'+','-','*','%','^','(',')' };
	int b[]={1,1,2,2,3,4,5};

	char str[100];
	
	
	printf("\nEnter infix string: ");
    scanf("%s", str);
	
	int i=0;
	for(i=0;str[i]!="/0";i++){
		/*if( 65<= (int)str[i] <=90 || 97<= (int)str[i]<=122 ){
			printf(" %c ",str[i]);
		}*/
		int j,f=0;
		for(j=0;j<7;j++){
			str[i]==a[j];
			f++;
		}
		if(f==1){
			if(s->top==-1){
				push(str[i],s);
			}else{
				if(str[i]==a[5]){
					push(str[i],s);
				}else{
					priority(str[i],s->a[s->top],s,a,b);
	
				}
			}
		}else{
			printf(" %c ",str[i]);
		}
		
	}
	
}
