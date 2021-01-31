//vijayasimhareddy
#include<stdio.h>
#include<stdlib.h>
struct tnode{
    struct tnode *right;
    int ele;
    struct tnode *left;
};
struct tnode * insert(struct tnode *root,int val){
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
                  temp = temp->left; }
            else{
                 temp->left = nn;
                 break;}     }
          else{
             if(temp->right != NULL){
                   temp=temp->right;}
             else{
                   temp->right=nn;
                   break;}    
              } 
        }
   }
  return root; 
}
struct tnode * findparent(struct tnode *temp1,struct tnode *temp){
    if(temp1->left != temp && temp1->right != temp){
          findparent(temp1->left,temp); 
          findparent(temp1->right,temp); 
              }
       return temp1; 
}
struct tnode * search(struct tnode *root,int val){
          struct tnode *temp;
          int f=0,c=1;
          temp = root;
             while(1){
               if (temp->ele == val){
                     printf("element found at %dth node\n",c);
                     f = 1;
                     break;}
               if(temp->ele > val){
                     if(temp->left != NULL){
                           temp=temp->left;}
                      else{
                            break;}   }
               else{
                     if(temp->right != NULL){
                          temp=temp->right;}
                      else{
                            break;}
                   }
                 c++;
                      }
             if(f==1){
                  return temp;}
             else{
                  printf("__element not found__\n");
                  return NULL;}
}

struct tnode * delete(struct tnode *root, int val){
      struct tnode *temp1,*temp,*parent;
      temp = search(root,val);
      if(temp != NULL){
     //node with no leaves
          if(temp->right == NULL && temp->left == NULL){
              //only root element in the tree
                if(temp == root){
                      root = NULL; }
               else{
               //other nodes
               parent = findparent(root,temp);
               if(parent->left == temp){
                   parent->left = NULL; 
                    }
               else{
                   parent->right = NULL;
                   }  
                    }          
               }
     //node with one leaf
       else if((temp->left != NULL && temp->right == NULL) || (temp->left == NULL && temp->right != NULL)){
           //root with one leaf
           if(temp == root && temp->right == NULL){
                    root->ele = temp->left->ele; 
                     root->left = NULL; }
           else if(temp == root && temp->left == NULL){
                    root->ele = temp->right->ele; 
                     root->right = NULL; }
           else{
          // other nodes with one leaf
           parent = findparent(root,temp);
           if(parent->left == temp){
                  if(temp->left == NULL){
                           parent->left = temp->right;
                           }
                 else if(temp->right == NULL){
                          parent->left = temp->left;
                             }
                                    }
          if(parent->right == temp){
              if(temp->left == NULL){
                          parent->right = temp->right;
                         }
              else if(temp->right == NULL){
                         parent->right = temp->left;
                             }
                                    }
              }
                            }
  //node with two leaves
          else{
         //to delete element right side of root
             if(val > root->ele){
              parent = temp;
              temp1 = temp->left;
              while(temp1->left != NULL){
                     parent = temp1;
                     temp1 = temp1->left;
                         }//while
               temp->ele = temp1->ele;
               parent->left = temp1->left;
                 }
           // to delete element left side of root
              else if(val < root->ele){
              parent = temp;
              temp1 = temp->right;
              while(temp1->right != NULL){
                     parent = temp1;
                     temp1 = temp1->right;
                       }//while
               temp->ele = temp1->ele;
               parent->right = temp1->right;
                 }
          //to delete root element
              else{
                parent = temp;
                temp1 = temp->right;
                while(temp1->left != NULL){
                     parent = temp1;
                     temp1 = temp1->left; 
                        }//while
                temp->ele = temp1->ele;
                if(parent != temp){
                parent->left = temp1->left; }
                 else{
                    parent->right = temp1->right; }
                    }
                  }
         } return root;
}

void display(struct tnode *root){
      if(root != NULL){
          printf("%d ",root->ele);
          display(root->left); 
          display(root->right);
          }
}
void main(){
    int op,val,dval;
    struct tnode *root;
    root = NULL;
    do{
     printf("enter the option\n\t1 for insert\n\t2 for delete\n\t3 for display\n\t4 for exit\n>>>>>");
     scanf("%d",&op);
     switch(op){
         case 1:{
             printf("enter the element ");
             scanf("%d",&val);
             root=insert(root,val);
             break;}
         case 2:{
             printf("enter the element ");
             scanf("%d",&dval);
             root=delete(root,dval);
             break;}
         case 3:{
             if(root == NULL){
                printf("__tree is empty__\n"); }
             display(root);
             printf("\n");
             break;}
         case 4:{
             printf("__exiting from tree__\n");
             break;}
             }
      }while(op != 4);
}
