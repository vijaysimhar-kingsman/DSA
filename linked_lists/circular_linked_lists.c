#include<stdio.h>
#include<stdlib.h>
struct node{
	int e;
	struct node*left;
	struct node*right;
};
struct node*head =NULL;

void insert(){
	int ele;
	printf("\nEnter the element: ");
	scanf("%d",&ele);
	if(head==NULL){
		head = (struct node *)malloc(sizeof(struct node));
		head->e=ele;
		head->left=head;
		head->right=head;
	}else{
		struct node*nn;
		nn=(struct node *)malloc(sizeof(struct node));
		nn->e=ele;
		
	
		struct node *temp;
		temp=head;
		while(temp->right!=head){
			
			temp=temp->right;
		}
		temp->right=nn;
		nn->left=temp;
		nn->right=head;	
		head->left=nn;
	}
}void addafter(){
	int pos;
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	
	if(pos<=length()){
		int ele;
		printf("\nEnter the element: ");
		scanf("%d",&ele);
		struct node*nn;
		nn=(struct node *)malloc(sizeof(struct node));
		nn->e=ele;
		struct node *temp;
		temp=head;
		
		if(pos==length()){
			temp->left->right=nn;
			nn->left=temp->left;
			temp->left=nn;
			nn->right=temp;
		}else{
			int c=0;
			while(c<pos-1){
				temp=temp->right;
				c++;
			}
			nn->left=temp;
			nn->right=temp->right;
			temp->right->left=nn;
			temp->right=nn;
		}
	}
}
void display(){
	if(head==NULL){
		printf("\ncircular linked list is empty....\n");
	}else{
		struct node*temp;
		temp=head;
		int i;
		i=0;
		while(i<2){
			if(temp==head && i==0){
				printf("%d-->",temp->e);
				temp=temp->right;
				i++;
			}else if(temp!=head){
				printf("%d-->",temp->e);
				temp=temp->right;
			}else if(temp==head){
				i++;
			}
		}
	}
}void addatbeginning(){
	if(head==NULL){
		insert();
	}else{
		struct node*n,*temp;
		
		n=(struct node*)malloc(sizeof(struct node));
		int ele;
		printf("\nEnter the element: ");
		scanf("%d",&ele);
		n->e=ele;
		temp=head;
		n->left= temp->left;
		temp->left->right=n;
		n->right=temp;
		temp->left=n;
		head=n;
		
		
	}
}void addinthemiddle(){
	int pos = length()/2;
	int ele;
	printf("\nEnter the element: ");
	scanf("%d",&ele);
	struct node*nn;
	nn=(struct node *)malloc(sizeof(struct node));
	nn->e=ele;
	struct node*temp;
	temp= head;
	int c=0;
	while(c<pos-1){
		temp=temp->right;
		c++;
	}
	nn->left=temp;
	nn->right=temp->right;
	temp->right->left=nn;
	temp->right=nn;		
}
void delet(){
	int pos;
	printf("\nEnter the position: ");
	scanf("%d",&pos);
	if(head!=NULL){
		if(pos>length()){
			printf("enter a valid position[1,%d]",length());
		}else if(length()<=2){
			if(pos==1 && length()==2){
				struct node *temp;
				temp=head;
				head=temp->right;
			//	temp->right->left=head;
				//temp->right->right=head;
				head->left=head;
				head->right=head;
				temp->right=NULL;
				temp->left=NULL;
				printf("__________present length :%d_____________",length());
				printf("\n\nsadfasdfasdf\n\n");
			}else if(pos==2 && length()==2){
				struct node*temp;
				temp=head;
				temp->right->left=NULL;
				temp->right->right=NULL;
				temp->left=head;
				temp->right=head;
			}else{
				head =NULL;
			}
			
		}else if(pos==1 && length()>2){
			struct node*temp;
			temp=head;
			temp->right->left=temp->left;
			temp->left->right=temp->right;
			head=temp->right;
			temp->left=NULL;
			temp->right=NULL; 
		}else if(pos==length()){
			struct node*temp,*temp1;
			temp=head;
			temp->left->left->right=temp;
			temp1=temp->left;
			temp->left=temp->left->left;
			temp1->left=NULL;
			temp1->right=NULL;
			
			
		}else if(1<pos<length()){
			int c;
			c=0;
			struct node*temp,*temp1;
			temp=head;
			while(c<pos-1){
				temp=temp->right;
				c++;
			}
			temp->right->left=temp->left;
			temp->left->right=temp->right;
			temp->right=NULL;
			temp->left=NULL;
		}else{
			printf("\nthe list is presently empty...........");
		}
	}else{
		printf("the list is presently empty...........####");
	}
}void find(){
	int ele;
	printf("\n enter the element: ");
	scanf("%d",&ele);
	struct node*temp;
	temp=head;
	int f=0;
	int i=0;
	while(i<2){
		if(temp->e==ele){
			f=1;
			break;
		}else{
			if(temp==head){
				i++;
				temp=temp->right;
			}else{
				temp=temp->right;
			}
				
		}
	}if(f==1){
		printf("\nelement found :)");
	}else{
		printf("\nelement not found");
	}
}
int length(){
	int count;
	if(head==NULL){
		printf("\ncircular linked list is empty....\n");
	}else{
		struct node*temp;
		temp=head->right;
		count=1;
		while(temp!=head){
			count++;
			temp=temp->right;
		}
	}return count;
}
int main(){
	int opt,len;

	do{
		printf("\nEnter\n 1.insert\n 2.addafter\n 3.Display\n 4.delete\n 5.find\n 6.add_at_beginnig\n 7.add_in_the_midlle\n 8.length\n 9.exit\n");
		scanf("%d",&opt);
	 	int i=0;
 		int ele;
		switch(opt){
				scanf("%d",&opt);
	 
 			
			case 1 :		
					insert();
					break;
			case 2 :addafter();
				break;
			case 3 :
					display();
					break;
			case 4 :delet();
					break;
			case 5 : find();
				break;
			case 6 : addatbeginning();
				break;
			case 7 : addinthemiddle();
				break;
			case 8 :len=length();
				printf("length of the list is %d____________",len);
				break;
			case 9 : exit(0);
				break;
			default:
					printf("invalid entery !!!!\n");
		}
	}while(opt!=9);	
}

