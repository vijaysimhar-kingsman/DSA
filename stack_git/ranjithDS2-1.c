//structures without using functions 

#include<stdio.h>
/*void push (int [],int,int);
void pop (int [],int);*/
struct stack{
	int a[10];
	int top;
	int sz;
};
int main(){
	
	struct stack s;
	s.top=-1;
	s.sz=10;
	int opt;
	
	do{
		printf("enter 1.push 2.pop 3.traversal 4.exit\n");
		scanf("%d",&opt);
	 	int i=0;
		switch(opt){
			
			case 1 : if (s.top == s.sz){
						printf("\nstack is full you cant add elements\n");
					}else{
						int ele;
						printf("Enter element : ");
						scanf("%d",&ele);
						s.top++;
						s.a[s.top]=ele;
						printf("%d element entered succesfully\n\n",ele);
						//push(s.a[10],ele,s.top);
					}
					break;
			case 2 : if(s.top==-1){
						printf("\nthere are no elements in the stack\n");
					}else{
						printf("%d element removed succesfully\n\n",s.a[s.top]);
						s.top--;
						//pop(s.a[10],s.top);
					}break;
			case 3 :
				for(i=0;i<=s.top;i++){
					printf("%d ",s.a[i]);
					}
					break;
				
			case 4 : exit(0);
				break;
			default:
					printf("invalid entery !!!!\n");
		}
	}while(opt!=4);
}/*void push(int arr[],int ele,int top){
	top++;
	arr[top]=ele;
	printf("%d element entered succesfully\n\n",ele);
}void pop(int arr[],int top){
	printf("%d element removed succesfully\n\n",arr[top]);
	top--;
}*/







