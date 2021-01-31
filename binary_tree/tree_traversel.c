//vijayasimhareddy
#include<stdio.h>
#include<stdlib.h>
struct tnode{
    struct tnode *right;
    int ele;
    struct tnode *left;
};
struct tnode * insert(struct tnode *root, int val){
     struct tnode *temp,*nn;
     if(root == NULL){
        root=(struct tnode *)malloc(sizeof(struct tnode));
        root->left=NULL;
        root->ele=val;
        root->right=NULL;}
     else{
       nn=(struct tnode *)malloc(sizeof(struct tnode));
       nn->left=NULL;
       nn->ele=val;
       nn->right=NULL;
       temp=root;
       while(1){
          if(temp->ele > val){
             if(temp->left != NULL){
                  temp=temp->left;}
            else{
                 temp->left=nn;
                 break;}     }
          else{
             if(temp->right != NULL){
                   temp=temp->right;}
             else{
                   temp->right=nn;
                   break;}    
              } 
            }
      } return root;
}
void pre_order(struct tnode *root){
       if(root != NULL){
            printf("%d ",root->ele);
            pre_order(root->left);
            pre_order(root->right);
                       }
}
void in_order(struct tnode *root){
       if(root != NULL){
            in_order(root->left);
            printf("%d ",root->ele);
            in_order(root->right);
                       }
}
void post_order(struct tnode *root){
       if(root != NULL){
            post_order(root->left);
            post_order(root->right);
            printf("%d ",root->ele);
                       }
}
void display(struct tnode *root){
  if(root != NULL){
   printf("%d ",root->ele);
   display(root->left);
   display(root->right);}
  else{
      return ;}
}


void main(){
    int op, ch;
    struct tnode *root;
    root = NULL;
    do{
     printf("enter the option\n\t1 for insert\n\t2 for pre_order\n\t3 for in_order\n\t4 for post_order\n\t5 for display\n\t6 for exit\n>>>>>");
     scanf("%d",&op);
     switch(op){
         case 1:{
              printf("enter the element ");
              scanf("%d",&ch);
              root=insert(root,ch);
             break;}
         case 2:{
             printf("__pre order__\n");
             pre_order(root);
             printf("\n");
             break;}
         case 3:{
             printf("__in order__\n");
             in_order(root);
             printf("\n");
             break;}
         case 4:{
             printf("__post order__\n");
             post_order(root);
             printf("\n");
             break;}
         case 5:{         
             display(root);
             printf("\n");
             break;
             }
         case 6:{
          printf("__exiting from tree__\n");
             break;}
          }
      }while(op != 6);
}

© 2021 GitHub, Inc.
