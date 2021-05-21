//QUEUE with n structure pointer

#include<stdio.h>
struct queue{
	int arr[5];
	int front;
	int rare;
	int sz;
};
int main(){
	struct queue *s;
	s=(struct queue *)malloc(sizeof(struct queue));
	s->front=-1;
	s->rare=-1;
	s->sz=5;
	int opt ,ele;
	do{
		
		printf("Enter 1.Enque\n\t2.Dequeue\n\t 3.Exit  : ");
		
		scanf("%d",&opt);
		
		switch(opt){                                                  
			case 1 :
				if(s->rare ==(s->sz)-1){
						printf("Queue is FULL :(\n\n");
					}else{
						(s->rare)++;
						printf("\nEnter element : ");
						scanf("%d",&ele);
						s->arr[s->rare]=ele;
					}break;
			case 2 :if(s->rare == s->front){
						printf("Queue is EMPTY :( \n\n");
					}else{
						s->front++;
						printf("\n%d element is dequeued from the array :)\n",s->arr[s->front]);
					
					}break;
			case 3 : exit(0);
						break;
			default:printf("\n\nEnter correctly idiot :| \n");
			
		}
	}while(opt!=3);
}
	
				 
