#include<stdio.h>
#include<stdlib.h>

struct node{
	int e;
	struct node* prev;
	struct node* next;
};
struct node* head = NULL;

int length();

void insert(){

	int ele;
	
	printf("\nenter element :");
	scanf("%d",&ele);
	
	
	if(head==NULL){
		head = (struct node *)malloc(sizeof(struct node));
		head -> e = ele;
		head -> next = head;
		head -> prev = head;
		
		
	}else{
		struct node *n;
		n = (struct node *)malloc(sizeof(struct node));
		n->e=ele;
		
		struct node *temp;
		temp = head;
		while(temp->next!=head){
			temp = temp->next;
			//printf("it has passed the code");

		}
		temp -> next = n;
		n -> prev=temp;
		head -> prev= n;
		n -> next = head;
		
	}
	
}
void display(){
	struct node *temp;
	temp = head;
	if(length()>0){
		while(temp->next!=head){
			printf("%d -->",temp->e);
			temp=temp->next;
		}printf("%d -->",temp->e);
	}else{
		printf("currently the circular linked list is empty");
	}
}
void delete(){
	
	int len =length();
	if(len>0){
		int choice;
		printf("which node you wanna delete : ");
		scanf("%d",&choice);
	
		int c=1;
		struct node *temp1,*temp2,*temp3;
		temp1= head;
		if(choice<=len && choice>0){
			if(choice!=1){
				while(c<choice){
					c++;
					temp2 = temp1;
					temp1= temp1->next; 	
				}
				
				temp3= temp1->next;
				if(temp3!=head){
					temp3->prev = temp2;
					temp2->next = temp3;
					temp1->next = NULL;
					temp1->prev = NULL;
				}else{
					temp2->next = temp1->next;
					head->prev = temp2;
					temp1->next = NULL;
					temp1->prev = NULL;
				}
			}else if(len ==1 && choice==1){
				head->next = NULL;
				head -> prev  = NULL;
				head=NULL;
				
			}else if(choice ==1){
				temp1 = head;
				head = temp1->next;
				temp1->prev->next = head;
				head->prev = temp1->prev;
				temp1->next =NULL;
				temp1->prev=NULL;
				
			}
			
			
		}else{
			printf("\nthere is no such node please enter 1 - %d",len);
		}
	}else{
		printf("there are no elements to delete");
	}
	
	
}
int length(){
	struct node* temp;
	temp=head;
	if(head!=NULL){
		int c = 1;
		while(temp->next!=head){
		
			temp=temp->next;
			c++;	
		}
		return c;
	}else{
		return 0;
	}
}
int main(){
	
	int opt;
	do{
		printf("\n1 to insert \n2 to delete\n3 to display\n4 to length\n5 to exit");
		scanf("%d",&opt);
		switch(opt){
			case 1 : insert();
					break;
			case 2 : delete();
					break;
			case 3 : display();
					break;
			case 4 :printf("length of the linked list is :%d ",length());
					break;
			default: printf("enter correctly ");
		}
	}while(opt!=5);
	
}
