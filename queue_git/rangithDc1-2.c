#include<stdio.h>
void enqueue(int [],int);
void dequeue(int [],int);
int main(){
	
	int n,front,rare,ele,opt;
	rare = front = -1;
	printf("entere the size of the array: ");
	scanf("%d",&n);
	int arr[n];
	do{
		printf("Enter 1.Enque\n\t2.Dequeue\n\t 3.Exit  : ");
		
		scanf("%d",&opt);
		
		switch(opt){
			case 1 :if(rare == n-1){
						printf("Queue is FULL :(\n\n");
					}else{
						rare++;
						
						enqueue(arr,rare);			
					}
			
				
			
					break;
			case 2 :if(rare == front){
						printf("Queue is EMPTY :( \n\n");
					}else{
						front++;
						dequeue(arr,front);
						
					
					}
		
				
					break;
			case 3 : exit(0);
						break;
			default:printf("\n\nEnter correctly idiot :| \n");
			
		}
	}while(opt!=3);

}void enqueue (int arr[],int rare){
	int ele;
	
		printf("\nEnter element : ");
		scanf("%d",&ele);
		arr[rare]=ele;					
	
}void dequeue (int arr[],int front){

		printf("\n%d element is dequeued from the array :)\n",arr[front]);
					
	
}