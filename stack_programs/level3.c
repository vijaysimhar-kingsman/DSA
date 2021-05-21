//structures without using functions 

#include<stdio.h>

struct stack{
	int a[10];
	int top;
	int sz;
};
struct stack push(struct stack s,int);
struct stack pop(struct stack s);
int main(){
	
	struct stack s;
	
	s.top=-1;
	s.sz=10;
	int opt;									
	
	do{
		printf("enter 1.push 2.pop 3.traversal 4.exit\n");
		scanf("%d",&opt);
		int j;
	 	
		switch(opt){
			
			case 1 : if (s.top == (s.sz-1)){
						printf("\nstack is full you cant add elements\n");
					}else{
						int ele;
						printf("Enter element : ");
						scanf("%d",&ele);
						
						
						//printf("%d is the top now\n\n",s.top);
						s=push(s,ele);
						
						/*s.a[s.top]=ele;
						//printf("%d element entered succesfully\n\n",ele);*/
						
					}
					break;
			case 2 : if(s.top==-1){
						printf("\nthere are no elements in the stack\n");
					}else{
						s=pop(s);
						
						
						
					}break;
			case 3 :
				
				for(j=0;j<=s.top;j++){
					printf("%d ",s.a[j]);
				}
					break;
				
			case 4 : exit(0);
				break;
			default:
					printf("invalid entery !!!!\n");
					break;
		}
	}while(opt!=4);
}struct stack push(struct stack s,int ele){
	s.top++;
	s.a[s.top]=ele;
	printf("%d element entered succesfully\n\n",ele);
	int i;
	for(i=0;i<=s.top;i++){
		printf("%d ",s.a[i]);
	}printf("\n\n");
	return s;
}struct stack pop(struct stack s){
	printf("%d element removed succesfully\n\n",s.a[s.top]);
	s.top--;
	//printf("%d is the top now\n\n",s.top);
	return s;
}







