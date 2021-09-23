#include<stdio.h>
#include<stdlib.h>
int length =0;
struct node{
	int e;
	struct node * left;
	struct node * right;
}; 
struct node * root = NULL;

struct node * insert ( struct node *,int ele);
struct node * find (struct  node *);
struct node * delete(struct node* root);
struct node * parent_node(struct node *,struct node *);

void display(struct node *root);
void preorder (struct node *);
void inorder (struct node *);
void postorder (struct node *);

                                              
int main(){
	int opt;
	do{
		printf("\n1 to insert \n2 to display\n3 to length\n4 to find\n5 to delete\n6 to exit\nEnter your choice: ");
		scanf("%d",&opt);
		struct node * val;
		int i;
		int  a[10] ={10,12,17,14,6,8,3,7,9,2};
		switch(opt){
			
			case 1 :for(i=0;i<10;i++){
						root =insert(root,a[i]);
					} length++;
					break;
			case 2 : display(root);
					break;
			case 3 : printf("current length of the tree is %d :",length);
					break;
					
			case 4 : val = find(root);
						if(val!=NULL){
							printf("\n--> %d is found in the tree <--",val->e);
						}else{
							printf("\nelement not found\n");
						}
					break;
			case 5 : root =delete(root);
						length--; 
					break;
			case 6 : break;
			default : printf("enter valid input :");
					break;
		}	
	}while(opt!=6);
}
struct node * insert(struct node * root,int ele){
	struct node* temp;
	temp = root;
	
	if( temp == NULL){
		root = (struct node *)malloc(sizeof(struct node));
		root->e= ele;
		root->left = NULL;
		root -> right = NULL;
	}else{
		struct node * nn;
		nn = (struct node *)malloc(sizeof(struct node));
		nn->e=ele;
		nn->right = NULL;
		nn->left = NULL;
		while(1){
			if(temp->e>ele){
				if(temp->left !=NULL){
					temp=temp->left;
				}else{
					temp->left = nn;
					break;
				}
			}else{
				if(temp->right!=NULL){
					temp= temp->right;
				}else{
					temp->right = nn;
					break;
				}
			}
		}
		
	}
	return root;
}struct node *  find(struct node * root){
	struct node * temp= root;
	if( root !=NULL){
		int ele;
		printf("enter element you wanna find/delete :");
		scanf("%d",&ele);
		
		while(1){
			if(temp->e == ele){
				return temp;
				
			}
			else if(temp->e>ele){
				if(temp->left!=NULL){
					temp =  temp -> left;
				}else{
					return NULL;
				}
			}else {
				if(temp->right!=NULL){
					temp = temp->right;
				}else{
					return NULL;
				}
			}
		}
		
		
	}else{
		return NULL;
	}
}
struct node * parent_node(struct node *root,struct node*ele_add){
	
		struct node * child = ele_add;
		int ele = ele_add->e;
		struct node* temp = root;
		while(temp!=NULL){
			if(temp->e>ele){
				if(temp->left ==child){
					return temp;
				}else{
					temp=temp->left;
				}
			}else{
				if(temp->right==child){
					return temp;
					
				}else{
					temp= temp->right;
				}
			}
			
		}return NULL;
		

}

struct node * delete(struct node * root){
	
	if( root != NULL){
		
		struct node * temp = root;
		struct node * ele_add = find(root);
		if(ele_add!=NULL){
			//printf("\n%d is the element you wannd find \n",ele_add->e);
			struct node * parent = ele_add;
			struct node * child = ele_add->right;
			if(ele_add->right!=NULL){
				while(child->left!=NULL){
					parent =child;
					child = child->left;
				}
				if(ele_add == parent){
					ele_add->e = child->e;
					parent->right = child->right;
				}else{
					ele_add->e = child->e;
					parent->left = child->right;
				}
				
				return root;
				
				
			}else{
				//printf("laaalaaa no right");
				if(ele_add!= root){
					struct node* parentnode = parent_node(root,ele_add);
					//printf("\n%d is the value of the parent node ",parentnode->e);
					if(ele_add == parentnode->right){
						parentnode->right = ele_add->left;
						//printf("yes its rigth to parent ");
					}else{
						parentnode->left = ele_add->left;
						//printf("child is left to parent");
					}
				}
				return root;
				
			}
			
		}else{
			printf("the element you entered is not there in the tree");
		}
		
		
		
		
	}else{
		printf("\n there are no elements to delete");
		return NULL;
	}
	
	
]
m}
void preorder(struct node *root){
	if(root!=NULL){
		printf(" %d ",root->e);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node *root){
	if(root!=NULL){
		
		inorder(root->left);
		printf(" %d ",root->e);
		inorder(root->right);
	}
}

void postorder(struct node *root){
	if(root!=NULL){
		
		postorder(root->left);
		postorder(root->right);
		printf(" %d ",root->e);
	}
}

void display(struct node * root){
	struct node * temp = root;
	
	printf("\nperorder traversal\n");
	preorder(temp);
	printf("\ninorder traversal\n");
	inorder(temp);
	printf("\npostorder traversal\n");
	postorder(temp); 
}
