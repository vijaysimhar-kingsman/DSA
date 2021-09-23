#include<stdio.h>
#include<stdlib.h>
struct queue{
	int a[25];
	int rare;
	int front;
	int size;
};
void enqueue (struct queue *q,int ele){
	if((q->front )>= (q->size )-1){
		printf("queue is full");
		
	}else{
		q->rare++;
		q->a[q->rare]=ele;
	}
}
int dequeue (struct queue * q){
	if(q->rare == q->front){
		printf("queue is empty");
	}else{
		q->front++;
		return q->a[q->front];
	}
}int isempty(struct queue *q){
	if(q->rare == q->front){
		return 1;
	}else{
		 return 0;
	}
}
int main(){
	int sz;
	printf("enter the size of your matrix: ");
	scanf("%d",&sz)	;
	int mat[sz][sz];
	int i=0,j=0;
	for(i=0;i<sz;i++){
		for(j=0;j<sz;j++){
			printf("enter element of a[%d][%d]",i,j);
			scanf("%d",&mat[i][j]);
		}
	}int visit[sz];
	for(i=0;i<sz;i++){
		visit[i]=0;
	}
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));   
	q->rare=q->front= -1;
	q->size=25;
	
	enqueue(q,0);
	int el;
	while(!isempty(q)){
		
		el = dequeue(q);
		if(visit[el]!=1){
			printf("%d ",el);
			visit[el]=1;
			
			
		}
		for(i=0;i<sz;i++){
			if(mat[el][i]==1 && visit[i]==0){
				enqueue(q,i);
			}
		}
	}
}












