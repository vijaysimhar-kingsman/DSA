#include<stdio.h>
void push(int,int,int[]);
void pop(int,int[]);
void exit(void);

int main(){
	int data[5];
	int size=5,top=-1,opt,ele;
 do{

	printf("enter 1.Push \t 2.Pop \t 3.Exit\n");
	scanf("%d",&opt);
	switch (opt){
		case 1 :
			if(top == size-1)
				printf("\nStack is full\n");
			else{
				top++;
				printf("\nEnter the element you wantend to push in stack : ");
				scanf("%d",&ele);
				push(ele,top,data);
			}
			
			
			break;
		case 2 :
			if(top ==-1)
				printf("\nthere are no elements to pop\n");
			else{
				pop(top,data);
				top--;
			}
			break;
		case 3 : exit();
			break;
		default : printf("Invalid Entry!!!!");
	}
 }while(opt!=3);
}
void push(int ele,int top,int data[]){
	data[top]=ele;
	top++;	
		
	printf("%d is insuerted successfully\n\n",ele);
}void pop(int top,int data[]){
	printf("%d is popped successfully\n\n",data[top]);

}








