 #include<stdio.h>
#include<stdlib.h>
struct node{
	
	int e;
	struct node *next;
};	struct node *head =NULL;

void insert(){
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	int ele;
	printf("\nEnter element : ");
	scanf("%d",&ele);
	n->e=ele;
	n->next=NULL;
	if(head==NULL){
		head=n;
		
		//printf("asdfasdfasdf");
		//
	}else{
		struct node *temp;
		temp=head;
	
		while(temp->next!=NULL){
			temp=temp->next;
		}temp->next=n;
		
		
	}
} void addafter(){
	
	int pos;
	printf("\nenter the position: ");
	scanf("%d",&pos);
	int c=0;
	struct node *temp;
	temp= head;
		
	while(c<pos-1){
		if(temp->next!=NULL){
			temp=temp->next;		
		}else{
			printf("\nthe position you entered is not available:(");
		}c++;
	}
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	int ele;
	printf("\nEnter element : ");
	scanf("%d",&ele);
	n->e=ele;
	n->next=temp->next;
	temp->next=n;	
}
	
void display(){
	struct node *temp1;

	temp1=head;
	if(head==NULL){
		
		printf("\nlist is empty...........\n");
	}else{
		while(temp1!=NULL){
			printf("%d-->",temp1->e);
			temp1=temp1->next;
		}	
	}
	
}void delet(){
	
	int num;
	printf("enter the element you wanted to delete: ");
	scanf("%d",&num);
	struct node *temp,*temp1;
	if(head->e!=num){
		
		temp = head;
		int f=0;
		while(temp!=NULL){
			if(temp->e==num){
				
				f=1;
				break;
			}else{
				temp1=temp;
				temp=temp->next;
			}
		}if(f==1){
			temp1->next= temp->next;	
		}else{
			printf("\n Element not found \n");
		}
	}else{
		temp =head;
		head = temp->next;
		
	}
	
}void find(){
	
	int num;
	printf("\nenter the element you wanted to delete: ");
	scanf("%d",&num);
	struct node *temp,*temp1;
	temp = head;
	int f=0;
	while(temp!=NULL){
		if(temp->e==num){
			
			f=1;
			break;
		}else{
			temp1=temp;
			temp=temp->next;  
		}
	}if(f==1){
		printf("\nelement found:)\n");
	}else{
		
		printf("\nelement not found \n");
	}
}void addatbeginning(){
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	int ele;
	printf("\nenter the element: ");
	scanf("%d",&ele);
	n->e=ele;
	n->next=head;
	head = n;
}void addinthemiddle(){
	
	struct node *temp,*temp1;
	int pos;
	temp=head;
	pos=length()/2;
//	printf("______%d______",pos);
	int c;
	c=0;
	if(head==NULL|| pos==0){
		insert();
	}else{
		while(c<pos){
			temp1=temp;
			temp=temp->next;
			c++;
		}
			struct node *n;
		n=(struct node*)malloc(sizeof(struct node));
		int ele;
		printf("\nenter the element: ");
		scanf("%d",&ele);
		n->e=ele;
		n->next=temp;
		temp1->next=n;
	}	

}
int length(){
	
	struct node *temp;
	temp = head;
	int count =0;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	//printf("______%d________",count);
	return count;
}
int main(){
	
	//int size;
	//printf("enter size of linked list: ");
	//scanf("%d",&size);

	
	int opt,len;

	do{
		printf("\nEnter 1.insert 2.addafter 3.traversal 4.delet 5.find 6.add_at_beginnig 7.add_in_the_midlle 8.length 9.exit\n");
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
	
