#include<stdio.h>
struct queue{
	int arr[5];
	int front;
	int rare;
};
struct queue enqueue(struct queue s, int);
struct queue dequeue(struct queue s);
int main(){
	struct queue s;
	s.front=s.rare=-1;
	int n=5;int opt ,ele;
	do{
		
		printf("Enter 1.Enque\n\t2.Dequeue\n\t 3.Exit  : ");
		
		scanf("%d",&opt);
		
		switch(opt){
			case 1 :if(s.rare == n-1){
						printf("Queue is FULL :(\n\n");
					}else{
						//#s.rare++;
						printf("\nEnter element : ");
						scanf("%d",&ele);
						//#s.arr[s.rare]=ele;
						s= enqueue(s,ele);
					}break;
			case 2 :if(s.rare == s.front){
						printf("Queue is EMPTY :( \n\n");
					}else{
						//#s.front++;
					//printf("\n%d element is dequeued from the array :)\n",s.arr[s.front]);
						s=dequeue(s);
						
					}break;
			case 3 : exit(0);
						break;
			default:printf("\n\nEnter correctly idiot :| \n");
			
		}
	}while(opt!=3);
}
struct queue enqueue (struct queue s,int ele){
	
	
		s.rare++;
		s.arr[s.rare]=ele;	
		return s;				
	
}struct queue dequeue (struct queue s){
		s.front++;
		printf("\n%d element is dequeued from the array :)\n",s.arr[s.front]);
		return s;			
	
}
	
