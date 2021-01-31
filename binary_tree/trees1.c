//vijayasimhareddy
#include<stdio.h>
#include<stdlib.h>
struct treenode* insert(struct treenode *,int );
void delet(struct treenode* ,int);
struct treenode{
	struct treenode *left;
	struct treenode *right;
	int e;
};
struct queue{
	struct treenode* a[20];
	int front,rare;
};

void enqueue(struct queue *q,struct treenode* temp){
	q->rare++;
	q->a[q->rare]=temp;	
//	printf("\n\nenqueued\n");
}
struct treenode * dequeue(struct queue *q){
	q->front++;
//	printf("\n\ndequeued\n");
	return q->a[q->front];
	
}
struct treenode* insert(struct treenode *root,int ele){
	if(root==NULL){
		struct treenode *temp;
		temp=(struct treenode*)malloc(sizeof(struct treenode));
		temp->e=ele;
		temp->left=NULL;
		temp->right=NULL;
		root=temp;
		//printf("asdf");
		return root;
	}else{
		struct queue *q;
		q=(struct queue *)malloc(sizeof(struct queue));
		q->rare=q->front=-1;
		struct treenode*temp;
		temp=root;
		enqueue(q,temp); 
		while(1){
			temp=dequeue(q);
			if(temp->left!=NULL)
				enqueue(q,temp->left);
			else
				break;
			if(temp->right!=NULL)
				enqueue(q,temp->right);
			else
				break;
		}struct treenode*n;
		n=(struct treenode *)malloc(sizeof(struct treenode));
		n->right=NULL;
		n->left=NULL;
		n->e=ele;
		if(temp->left==NULL){
			temp->left=n;
			////printf("element entered #l");
		}else{
			temp->right=n;
			//printf("element entered #r");
		}return root;
		free(q);
	}
		
}
void print(struct treenode* root){
	if(root!=NULL){
		struct treenode* temp;
		temp=root;
		struct queue *q;
		q=(struct queue*)malloc(sizeof(struct queue));
		q->rare=q->front=-1;
		enqueue(q,temp);
		int c=0;
	
		while(q->rare!=q->front){
			temp=dequeue(q);
			if(temp->left!=NULL){
				enqueue(q,temp->left);
			}if(temp->right!=NULL){
				enqueue(q,temp->right);
			}printf("%d ",temp->e);
			
		}
	}else{
		printf("\n\ncurrently tree is EMPTY.....");
	}
}
int length(struct treenode* root){
	if(root!=NULL){
		struct treenode* temp;
		temp=root;
		struct queue *q;
		q=(struct queue*)malloc(sizeof(struct queue));
		q->rare=q->front=-1;
		enqueue(q,temp);
		int c=0;
		
		while(q->rare!=q->front){
			temp=dequeue(q);
			if(temp->left!=NULL){
				enqueue(q,temp->left);
			}if(temp->right!=NULL){
				enqueue(q,temp->right);
			}c++;
			
		}//printf("there are %d elements in the tree....",c);
		return c;
	}
}
void pop(struct treenode* root){
	if(root!=NULL){
			struct treenode* temp,* temp1;
			temp=root;
			struct queue *q;
			q=(struct queue*)malloc(sizeof(struct queue));
			q->rare=q->front=-1;
			enqueue(q,temp);
			int j=0;int l,r,t,t1;
			l=r=t=t1=0;
			while(q->rare!=q->front && j==0){
				temp1=temp;
				temp=dequeue(q);
				if(temp->left!=NULL){
					enqueue(q,temp->left);
				}else{
					j++;l=1;
				}
				if(temp->right!=NULL){
					enqueue(q,temp->right);
				}else{
					r=1;j++;
				}if(r==1 && l==1){
					if(temp1->right!=NULL){
						temp1->right=NULL;
					}
				}else if(r==1){
					temp->left=NULL;
				}
			}
		
	}else{
		printf("\n\ncurrently tree is EMPTY.....");
	}
}
struct treenode* find(struct treenode* root,int ele){
	if(root!=NULL){
		struct treenode* temp,*temp1;
		temp=root;
		struct queue *q;
		q=(struct queue*)malloc(sizeof(struct queue));
		q->rare=q->front=-1;
		enqueue(q,temp);
		int f=0;
		
		while(q->rare!=q->front){
			
			temp=dequeue(q);
			if(temp->left!=NULL){
				enqueue(q,temp->left);
			}if(temp->right!=NULL){
				enqueue(q,temp->right);
			}if(temp->e==ele){
				f=1;
				temp1=temp;
			}
			
		}if(f==1){
			return temp1;
		}else
			printf("\nElement not found :( ");
		
		
	}else{
		printf("\n\ncurrently tree is EMPTY.....");
	}
}
struct treenode* lastnode(struct treenode* root){
	if(root!=NULL ){
		if(length(root)>1){
			struct treenode* temp,* temp1;
			temp=root;
			struct queue *q;
			q=(struct queue*)malloc(sizeof(struct queue));
			q->rare=q->front=-1;
			enqueue(q,temp);
			int j=0;int l,r,t,t1;
			l=r=t=t1=0;
			while(q->rare!=q->front && j==0){
				temp1=temp;
				temp=dequeue(q);
				if(temp->left!=NULL){
					enqueue(q,temp->left);
				}else{
					j++;l=1;
				}
				if(temp->right!=NULL){
					enqueue(q,temp->right);
				}else{
					r=1;j++;
				}if(r==1 && l==1){
					if(temp1->right!=NULL){
						return temp1->right;
					}
				}else if(r==1){
					return temp->left;
				}
			}
		}else{
			return root;
		}
	}else{
		printf("\n\ncurrently tree is EMPTY.....");
	}
}
struct treenode* parentnode(struct treenode * root,struct treenode*temp1){
	if(root!=NULL ){
			struct treenode* temp;
			temp=root;
			struct queue *q;
			q=(struct queue*)malloc(sizeof(struct queue));
			q->rare=q->front=-1;
			enqueue(q,temp);
			
			while(q->rare!=q->front ){
			
				temp=dequeue(q);
				if(temp->left==temp1){
					return temp;
				
				}else{
					if(temp->left!=NULL){
						enqueue(q,temp->left);
					}
				}
				if(temp->right==temp1){
					return temp;
				}else{
					if(temp->left!=NULL){
						enqueue(q,temp->right);
					}
				}
			}
		
	}else{
		printf("\n\ncurrently tree is EMPTY.....");
	}
}
void delet(struct treenode*root,int num){
	struct treenode *temp,*temp1,*temp2;
	temp=find(root,num);
	temp1=lastnode(root);
	temp2=parentnode(root,temp1);

	/**here temp is the address of the element  we wanted to delete
	, temp1 is the last node of the tree
	and temp2 is the parent node the last node of the tree**/
	
	if(temp->e!=temp1->e){
		temp->e=temp1->e;
		if(temp1==temp2->left){
			temp2->left=NULL;
		}else{
			temp2->right=NULL;
		}free(temp1);
	}
	else{
		pop(root);
	}

}
int main(){
	struct treenode *root =NULL;
	int ele,len;
	int opt;int num;
	struct treenode *temp;
	do{
		printf("\nEnter 1.insert 2.print 3.pop 4.find 5.length 6.delete 7.exit\n");
		scanf("%d",&opt); 
		switch(opt){	
			case 1 :printf("\nEnter element : ");
					scanf("%d",&ele);		
					root=insert(root,ele);
					break;
			case 2 :
					print(root);
					break;
			case 3 :if(length(root)>1)
						pop(root);
					else{
						root=NULL;
					}
					break;
			case 4 :	
					printf("\nenter number tou wanna find: ");
					scanf("%d",&num);
					temp=find(root,num);
					if(temp->e==num){
						printf("\nelement found :)");
					}
				break;
			case 5 :len=length(root);
					 printf("length of the list is %d____________",len);
				break;
			case 6 :
					printf("\nenter number you need to delete: ");
					scanf("%d",&num);
					if(root->e!=num){
						delet(root,num);
					}else{
						pop(root);
					}
					break;
			case 7 : exit(0);
				break;
			default:
					printf("invalid entery !!!!\n");
		}
	}while(opt!=7);
}	












