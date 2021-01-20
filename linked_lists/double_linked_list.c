#include<stdio.h>
#include<stdlib.h>
int length();
struct node{
	struct node *left;
	int e;
	struct node *right;
};struct node *head = NULL;
void insert(){
	int ele;
	printf("\nEnter the element: ");
	scanf("%d",&ele);
	if(head==NULL){
		head = (struct node *)malloc(sizeof(struct node));
		head->e=ele;
		head->left=NULL;
		head->right=NULL;
	}else{
		struct node*nn;
		nn=(struct node *)malloc(sizeof(struct node));
		nn->e=ele;
		
		nn->right=NULL;
		struct node *temp;
		temp=head;
		while(temp->right!=NULL){
			
			temp=temp->right;
		}temp->right=nn;
		nn->left=temp;	
	}
}void addafter(){
	int pos;
	printf("\nEnter position: ");
	scanf("%d",&pos);
	struct node*temp;
	temp=head;
	int c=0;
	int len ;
	
	if(pos<=length()){
		struct node *n;
		n=(struct node*)malloc(sizeof(struct node));
		int ele;
		printf("\nEnter the element: ");
		scanf("%d",&ele);
		n->e=ele;
		while(c<pos-1){
			temp=temp->right;
			c++;
		}if(temp->right!=NULL){
			
				n->right=temp->right;
				temp->right->left=n;
				n->left=temp;
				temp->right=n;		
		}else{
			n->right=NULL;
			n->left=temp;
			temp->right=n;
		}
	}else{
		printf("\nEnter between[1,%d] ",length());
	}
}
void addatbeginning(){
	int ele;
	printf("\nEnter the element: ");
	scanf("%d",&ele);
	if(head==NULL){
		head = (struct node *)malloc(sizeof(struct node));
		head->e=ele;
		head->left=NULL;
		head->right=NULL;
	}else{
		struct node*nn;
		nn=(struct node *)malloc(sizeof(struct node));
		nn->e=ele;
		nn->left=NULL;
		nn->right=head;
		head->left=nn;
		head=nn;
		
	}
}void addinthemiddle(){
	int pos = length()/2;
	if(pos==0 || head==NULL){
		insert();
	}else{
		int c=0;
		struct node *temp;
		temp=head;
		while(c<pos){
			temp=temp->right;
			c++;
		}
		struct node*nn;
		nn=(struct node *)malloc(sizeof(struct node));
		int ele;
		printf("\nEnter the element: ");
		scanf("%d",&ele);
		nn->e=ele;
		
		temp->left->right=nn;
		nn->left=temp->left;
		nn->right=temp;
		temp->left=nn;
	}
	
	
	
}
void display(){
	if(head==NULL){	
		printf("\nthere are no elements.................");	
	}else{
		struct node*temp;
		temp=head;
		while(temp!=NULL){
			printf("%d-->",temp->e);
			temp=temp->right;
		}	
	}
}void delet(){
	int pos;
	printf("\nEnter the position[1,len]:  ");
	scanf("%d",&pos);
	if(head!=NULL){
		
	
		if(pos==1){
			struct node*temp;
			temp=head;
			head=temp->right;
			temp->right=NULL;
		}else{
			struct node *temp;
			temp=head;
			int c;
			c=0;
			while(c < pos-1){
				temp=temp->right;
				c++;
				//printf("asdfasdfa");
			}
			if(temp->right!=NULL){
				temp->right->left=temp->left;
				temp->left->right=temp->right;
				temp->right=NULL;
				temp->left=NULL;	
			}
			else{
				temp->left->right=NULL;
				temp->left=NULL;
			}
		}
	}else{
			
		printf("\nthere are no elements left to delete in the list.");
	}
	
	
}void find(){
	int ele;
	printf("\nEnter the element: ");
	scanf("%d",&ele);
	struct node *temp;
	temp=head;
	int f;
	f=0;
	while(temp!=NULL){
		if(temp->e==ele){
			f++;
			break;
		}else{
			temp=temp->right;
		}	
	}if(f==1){
		printf("\nElement found :) \n");
	}else{
		printf("\nElement not found :( \n");
	}
}int length(){
	struct node *temp;
	temp=head;
	int count;
	count =0;
	while(temp!=NULL){
		count ++;
		temp=temp->right;
	}
	//
	return count;
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