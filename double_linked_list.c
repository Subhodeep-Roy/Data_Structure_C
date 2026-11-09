#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int info;
    struct node *next;
};

void traverse(struct node **start){
    struct node *q=(*start);
    if(*start==NULL){
        printf("NULL linked list");
    }else{
        for(;q!=NULL;q=q->next){
            printf("->%d ",q->info);
        }
    }
}

void inst_beg(struct node ** start,int num){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->info=num;
    temp->next=*start;
    if(*start!=NULL){
        (*start)->prev=temp;
    }else{
        (*start)=temp;
    }
}

void inst_end(struct node **start,int num){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *q=(*start);
    temp->info=num;
    temp->next=NULL;
    if(*start==NULL){
        temp->prev=NULL;
    }else{
        for(;q!=NULL;q=q->next);
        temp->prev=q;
        q->next=temp;
    }
}

void inst_aft_ele(struct node **start,int num){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *q=(*start);
    temp->info=num;
    if(*start==NULL){
        return;
    }
    for(;q!=NULL && q->info!=num;q=q->next);
    if(q!=NULL){
        temp->next=q->next;
        temp->prev=q;

        if(q->next!=NULL){
            q->next->prev=temp;
        }else{
            q->next=temp;
        }
    }
}

void inst_aft_pos(struct node **start,int num,int pos){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    struct node*q=(*start);

    temp->info=num;

    if(*start=NULL){
        return;
    }
    else if(pos==1){
        temp->prev=NULL;
        temp->next=*start;
        (*start)->prev=temp;
        *start=temp;
    }
    else{
        for(int i=1;i<pos-1;i++){
            q=q->next;
            if(q==NULL){
                return;
            }
        }
        temp->next=q->next;
        temp->prev=q;
        if(q->next!=NULL){
            q->next->prev=temp;
        }
        q->next=temp;
    }
}

void del_beg(struct node **start){
    struct node *q=(*start);
    if(*start==NULL){
        return;
    }else{
        (*start)=(*start)->next;
        if (*start!=NULL){
            (*start)->prev=NULL;
        }
        free(q);
    }
}

void del_end(struct node **start){
    struct node *q=(*start);
    if(*start==NULL){
        return;
    }else if((*start)->next==NULL){
        *start=NULL;
        free(q);
    }
    else{
        for(;q!=NULL;q=q->next){
            if(q==NULL){
                return;
            }
        }
        q->prev->next=NULL;
        free(q);
    }
}

void del_ele(struct node **start,int num){
    struct node *q=(*start);
    if(*start==NULL){
        return;
    }
    else if((*start)->info==num){
        if((*start)->next==NULL){
            *start=NULL;
            free(q);
        }else{
            (*start)->next->prev=NULL;
            (*start)=(*start)->next;
            free(q);
        }
    }else{
        for(;q!=NULL && q->info!=num;q=q->next){
            if(q==NULL){
                return;
            }
        }
        q->prev->next=q->next;
        if(q!=NULL){
            q->next->prev=q->prev;
        }
        free(q);
    }
}

void del_pos(struct node **start,int pos){
    struct node *q=(*start);
    if((*start)==NULL){
        return;
    }else if(pos==1){
        if((*start)->next==NULL){
            *start=(*start)->next;
            free(q);
        }else{
            (*start)->next->prev=NULL;
            *start=(*start)->next;
            free(q);
        }
    }else{
        for(int i=0;i<pos-1;i++){
            if(q!=NULL){
                q=q->next;
            }else{
                return;
            }
        }
        q->prev->next=q->next;
        q->next->prev=q->prev;
    }
}

void_reverse(struct node **start){
    struct node *p1,*p2;

    p1=(*start);
    p2=(*start)->next;

    p1->next=NULL;
    p1->prev=p2;
    while(p2!=NULL){
        p2->next=p1;
        p2->prev=p2->next;
        p1=p2;
        p2=p2->next;
    }
    *start=p1;
}

int main(){

    int k=1,q=0;
    struct node *n1=NULL;



    // while(k>0){
    //     printf("\n___________________________________________\n");
    //     printf("\n1 to display\n");
    //     printf("2 to INsert element at the begining\n");
    //     printf("3 to insert element at the end\n");
    //     printf("4 to insert element at particular position\n");
    //     printf("5 to insert element after a number existing in the linked list\n");
    //     printf("6 to del element from the beginning\n");
    //     printf("7 to del element from the ending\n");
    //     printf("8 to del element from the particular position\n");
    //     printf("9 to search and del element\n");
    //     printf("10 to sort the linked list\n");
    //     printf("11 to reverse the linked list\n");
    //     printf("12 to insert element in a sorted linked list\n");
    //     printf("\n\n\nEnter choice: ");
    //     scanf("%d",&q);
    //     if(q==2){
    //         int h;
    //         printf("Enter element: ");
    //         scanf("%d",&h);
    //         inst_beg(&n1,h);
    //     }else if(q==1){
    //         traverse(&n1);
    //     }else if(q==3){
    //         int p;
    //         printf("Enter element: ");
    //         scanf("%d",&p);
    //         inst_end(&n1,p);
    //     }else if(q==4){
    //         int p,q;
    //         printf("Enter number , pos :");
    //         scanf("%d%d",&p,&q);
    //         inst_pos(&n1,p,q);
    //     }else if(q==5){
    //         int p,q;
    //         printf("Enter number , before element :");
    //         scanf("%d%d",&p,&q);
    //         inst_aft_ele(&n1,p,q);
    //     }else if(q==6){
    //         del_beg(&n1);
    //     }else if(q==7){
    //         del_end(&n1);
    //     }else if(q==8){
    //         int t;
    //         printf("Enter pos: ");
    //         scanf("%d",&t);
    //         del_pos(&n1,t);
    //     }else if(q==9){
    //         int t;
    //         printf("Enter element to del: ");
    //         scanf("%d",&t);
    //         search_del(&n1,t);
    //     }else if(q==10){
    //         ll_sorting(&n1);
    //     }else if(q==11){
    //         reversing(&n1);
    //     }else if(q==12){
    //         int p;
    //         printf("Enter element to add: ");
    //         scanf("%d",&p);
    //         add_ele_srt_ll(&n1,p);
    //     }
    //     else{
    //         k=-1;
    //         break;
    //     }
    // }

    return 0;

}