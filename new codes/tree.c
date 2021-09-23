#include<stdio.h>
#include<stdlib.h>
struct tnode{
	int e;
	struct tnode *left;
	struct tnode *right;
	
};struct tnode * root;

struct queue{
	struct tnode *a[20];
	int front,rare,sz;
};
void enqueue(struct queue * , struct tnode * );
struct tnode* dequeue(struct queue *);

struct tnode* insert(struct tnode *);
void display(struct tnode *);
int length(struct tnode *);

struct tnode * findaddress(int ,struct tnode *);
struct tnode * last_node(struct tnode *  );
struct tnode * parent_node(struct tnode *  , struct tnode *);
struct tnode* delete(struct tnode *);
int main(){
	int opt;
	do{
		printf("\n1 to insert \n2 to display\n3 to length\n4 to find\n5 to delete\n6 to exit\nEnter your choice: ");
		scanf("%d",&opt);
		switch(opt){
			
			case 1 : root =insert(root);
					break;
			case 2 : display(root);
					break;
			case 3 : printf("current length of the tree is %d :",length(root));
					break;
			case 4 : printf("--> %d <--",find(root));
					break;
			case 5 : root =delete(root); 
					break;
			case 6 : break;
			default : printf("enter valid input :");
					break;
		}	
	}while(opt!=6);
	
}


void enqueue(struct queue *q , struct tnode * temp){
	q->rare++;
	if(q->rare < q->sz){
		q->a[q->rare]=temp;
	}else{
		printf("\nQueue is full");
	}
}
struct tnode* dequeue(struct queue *q ){
	if(q->front == q->rare){
		printf("queue is empty");
	}else{
		q->front++;
		return q->a[q->front];
		
		
	}
}
struct queue * create_q(){
	struct queue *q;
	q= (struct queue*)malloc(sizeof(struct queue));
	q->front=-1;
	q->rare=-1;
	q->sz=20;
	return q;
		
}

//		INSERT
struct tnode * insert(struct tnode* root){
	int ele;
	printf("enter element :");
	scanf("%d",&ele);
	struct tnode * temp;
	if( root == NULL){
		root = (struct tnode *)malloc(sizeof(struct tnode));
		root -> e = ele;
		root -> right= NULL;
		root -> left = NULL;
		printf("\ninserted\n");
		
	}else{
		struct tnode *nn;
		nn=(struct tnode*)malloc(sizeof(struct tnode));
		nn->e =ele;
		nn->left=NULL;
		nn->right=NULL;
		
		struct tnode * temp;
		temp=(struct tnode*)malloc(sizeof(struct tnode));
		temp = root;
		
		struct queue *q;
		q = create_q();
		
		enqueue(q,temp);
		
		while(1){
			temp = dequeue(q);
			
			if(temp->left !=NULL){
				enqueue(q,temp->left);
			}else{
				
				break;
			}
			if(temp->right !=NULL){
				enqueue(q,temp->right);
			}else{
				break;
			}
		}if(temp->left == NULL){
			temp->left = nn;
		}else{
			temp->right =nn;
		}free(q);
	}
	return root;
	
}

//		DISPLAY
void display(struct tnode* root){
	
	if(root!=NULL){
		struct tnode * temp;
		temp=root;
		struct queue *q;
		q= create_q();
		
		enqueue(q,temp);
		while(q->rare!=q->front){
			temp=dequeue(q);
		
			if(temp->left!=NULL){
				enqueue(q,temp->left);
			}if(temp->right!=NULL){
				enqueue(q,temp->right);
			}printf(" %d ",temp->e);
		}free(q);
	}else{
		printf("\ncurrently there are no elements in the tree\n");
	}
	
	
}
//		LENGTH

int length(struct tnode * root){
	if(root!=NULL){
		struct tnode * temp;
		temp=root;
		struct queue *q;
		q= create_q();
		int c=0;
		enqueue(q,temp);
		while(q->rare!=q->front){
			temp=dequeue(q);
		
			if(temp->left!=NULL){
				enqueue(q,temp->left);
			}if(temp->right!=NULL){
				enqueue(q,temp->right);
			}c++;
		}free(q);
		return c;
	}else{
		
		return 0;
	}	
}
//		FIND
int find(struct tnode * root){
	if(root!=NULL){
		struct tnode * temp;
		temp=root;
		struct queue *q;
		q= create_q();
		int c=0;
		int ele;
		printf("\nenter element you wanna find :");
		scanf("%d",&ele);
		enqueue(q,temp);
		while(q->rare!=q->front){
			temp=dequeue(q);
		
			if(temp->left!=NULL){
				enqueue(q,temp->left);
			}if(temp->right!=NULL){
				enqueue(q,temp->right);
			}if(temp->e == ele){
				c++;
				break;
			}
		}free(q);
		if(c==1){
			return 1;
		}else{
			return 0;
		}
	}else{
		
		return 0;
	}	
}
struct tnode * findaddress(int ele,struct tnode *root){
	if(root!=NULL){
		struct tnode * temp,*temp1;
		temp=root;
		struct queue *q;
		q= create_q();
		enqueue(q,temp);
		int c=0;
		while(q->rare!=q->front){
			temp=dequeue(q);
		
			if(temp->left!=NULL){
				enqueue(q,temp->left);
			}if(temp->right!=NULL){
				enqueue(q,temp->right);
			}if(temp->e == ele && c==0){
				//return temp;
				c++;
				temp1= temp;
			}
		}free(q);
		if(c==1){
			return temp1;
		}else{
			return NULL;
		}
		
	}else{
		
		return NULL;
	}		
}struct tnode * last_node(struct tnode * root){
	if(root!=NULL){
		struct tnode * temp;
		temp=root;
		struct queue *q;
		q= create_q();
		
		enqueue(q,temp);
		while(q->rare!=q->front){
			temp=dequeue(q);
		
			if(temp->left!=NULL){
				enqueue(q,temp->left);
			}if(temp->right!=NULL){
				enqueue(q,temp->right);
			}
			
		}free(q);
		return temp;
	}else{
		return NULL;
	}
	
}
struct tnode * parent_node(struct tnode * root , struct tnode *child_node_add){
	if(root!=NULL){
		struct tnode * temp;
		temp=root;
		struct queue *q;
		q= create_q();
		
		enqueue(q,temp);
		while(q->rare!=q->front){
			temp=dequeue(q);
			if(temp->right == child_node_add){
				return temp;
			}else if(temp->left == child_node_add){
				return temp;
			}
			if(temp->left!=NULL){
				enqueue(q,temp->left);
			}if(temp->right!=NULL){
				enqueue(q,temp->right);
			}
			
		}free(q);
		
	}else{
		return NULL;
	}
	
}
struct tnode * delete(struct tnode * root){
	//things to find
	//node address of ele
	//node address of last element
	// node address of the parent of last element
	struct tnode * temp = root;
	if(root ==NULL){
		printf("\nthis tree is currently empty");
	}
	else if(length(root)==1){
		int ele;
		printf("enter element :");
		scanf("%d",&ele);
		struct tnode *e_add;
		e_add = findaddress(ele,root);
		
		if(e_add!=NULL){
			printf("\nthis is the last element in the tree");
		
			root =NULL;
			return root;
		}else{
			printf("the element you enter is not in the list ");
		}
		
		
	}else{
		int ele;
		printf("enter element you wanna delete :");
		scanf("%d",&ele);
		//lets find the node address of the ele
		struct tnode *e_add;
		e_add = findaddress(ele,root);
		if(e_add!=NULL){
			//printf("%d ->>> isthe element's address we got",e_add->e); working fine
			//lets find the last node		
			struct tnode *last_node_add;
			last_node_add = last_node(root);	
			//printf("%d ->>> isthe element's address we got",last_node_add->e); working fine
			//we got the last node ,lets find its parent node
			struct tnode *parent_node_add;
			parent_node_add = parent_node(root,last_node_add);
			//printf("%d ->>> is the last element parent node address we got",parent_node_add->e); working fine
			e_add->e = last_node_add->e;
			if(parent_node_add->left == last_node_add){
				parent_node_add->left =NULL;
			}else{
				parent_node_add->right = NULL;
			}					
		}else{
			printf("\nsorry there is no such element in the tree");
			
		}
	}
	
	return root;
}

