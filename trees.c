#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *lchild;
    struct node *rchild;
};

traverse_preorder(struct node* ptr){
    if(ptr!=NULL){
        printf("%c",ptr->info);
        traverse_preorder(ptr->lchild);
        traverse_preorder(ptr->rchild);
    }
}

traverse_inorder(struct node* ptr){
    if(ptr!=NULL){
        traverse_inorder(ptr->lchild);
        printf("%c",ptr->info);
        traverse_inorder(ptr->rchild);
    }   
}

traverse_postorder(struct node* ptr){
    if(ptr!=NULL){
        traverse_postorder(ptr->lchild);
        traverse_postorder(ptr->rchild);
        printf("%c",ptr->info);
    }
}

int main(){

}