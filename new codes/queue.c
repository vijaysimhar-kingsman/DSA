#include<stdio.h>
#include<stdlib.h>
struct queue{
	int *a;
	int sz;
	int rare;
	int front;
};
void push(struct queue *);
void pop(struct queue *);
void display(struct queue *);
int main(){
	struct queue *q;
	q= (struct queue *)malloc(sizeof(struct queue));
	q->rare=-1;
	q->front=-1;
	printf(" enter the size of the queue : ");
	scanf("%d",&q->sz);
	q->a=(int *)malloc(q->sz*sizeof(int));
	int opt =1;
	do{
		printf("\nenter \n1 to push\n2 to pop\n3 to display\n4 to exit");
		scanf("%d",&opt);
		switch(opt){
			case 1 : push(q);
			break;
			case 2 : pop(q);
			break;
			case 3 : display(q);
			break;
			case 4 : break;
			default: printf("\nplease enter a valid option ");
		}
	}while(opt!=4);
	
}void push(struct queue *q){
	if(q->rare >= q->sz-1){
		printf("\nthe queue is full");
	}else{
		q->rare++;
		int ele;
		printf("\nEnter element you wanna push into queue: ");
		scanf("%d",&ele);
		q->a[q->rare]=ele;
		printf("element entered successfully");
		
	}
}void pop(struct queue *q){
	if(q->rare
	 == q->front){
		printf("\nqueue is empty");
		
	}else{
		q->front++;
		printf("%d element is deleted succesfully from the ",q->a[q->front]);
	}
}void display(struct queue *q){
	int i;
	if(q->rare != q->front){
		if(q->front==-1){
			for(i=0;i<=q->rare;i++){
				printf(" %d ",q->a[i]);
			}
		}else{
			for(i=q->front;i<=q->rare;i++){
				printf(" %d ",q->a[i]);
			}
		}
		
	}
}
