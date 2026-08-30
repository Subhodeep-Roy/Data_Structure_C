#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

void insertion_begining(struct node **start,int num){
    struct node* temp =(struct node*)malloc (sizeof(struct node));

    temp -> info =num;
    temp->next =*start;
    (*start)=temp;
}

void insertion_end(struct node **start,int num){
    struct node *temp =(struct node*)malloc(sizeof(struct node));
    struct node *q;

    temp -> info= num;
    temp -> next= NULL;
    if(*start == NULL){
        (*start)=temp;
    }else{
        for(q=*start;q->next !=NULL;q=q->next);
        q->next = temp;
    }
}

void insertion_aft_ele(struct node **start,int aft,int num){
    struct node *temp=(struct node *)malloc(sizeof(struct node));

    temp->info=num;
    if(*start==NULL){
        free(temp);
        return ;
    }else{
        struct node *q;
        for(q=*start;q!=NULL && q->info!=aft;q=q->next);
        if(q!=NULL){
            temp->next = q->next;
            q->next= temp;
        }else{
            free(temp);
        }
    }
}

void insertion_at_pos(struct node **start,int pos,int num){
    struct node *temp=(struct node*)malloc (sizeof(struct node));

    temp->info = num;
    if(*start==NULL && pos!=1){
        return ;
    }
    else if (pos==1){
        temp->next=*start;
        *start=temp;
    }else{
        struct node *q;
        q=*start;
        for(int i=1;i<pos-1;i++){
            q=q->next;
            if(q==NULL){
                return;
            }
        }
        temp->next =q->next;
        q->next=temp;
    }
}

void deletion_begining(struct node ** start){
    struct node *q=*start;
    if(*start==NULL){
        return;
    }else{
        *start=q->next;
        free(q);
    }
}

void deletion_end(struct node **start){
    struct node *prev,*q=*start;
    if(*start==NULL){
        return;
    }else if((*start)->next==NULL){
        *start=NULL;
        free(q);
    }
    else{
        for(;q->next!=NULL;q=q->next){
            prev=q;
            
        }
        prev->next=NULL;
        free(q);
    }    
}

void deletion_ele(struct node **start,int ele){
    struct node *prev,*q=*start;
    if(*start==NULL){
        return;
    }else if((*start)->info==ele){
        (*start)=(*start)->next;
        free(q);
    }
    else{
        for(;q->info!=ele;q=q->next){
            prev=q;
        }
        prev->next=q->next;
        free(q);
    }
}

void deletion_ele_pos(struct node ** start,int pos){
    struct node *prev,*q=*start;

    if(*start==NULL){
        return;
    }else if(pos==1){
        (*start)=(*start)->next;
    }else{
        for(int i=1;i<pos;i++){
            prev=q;
            q=q->next;
            if(q==NULL){
                return;
            }
        }
        prev->next=q->next;
        free(q);
    }
}

void count(struct node* start){
    struct node *q;
    int c=0;
    printf("No of element : \n");
    if(start==NULL){
        printf("%d",c);
        return ;
    }else{
        for(q=start;q!=NULL;q=q->next){
            c++;
        }
    }

    printf("%d",c);
}

void print(struct node* start){
    struct node *q;
    printf("Linled list : \n");
    if(start==NULL){
        printf("-> NULL");
    }else{
        for(q=start;q!=NULL;q=q->next){
            printf("-> %d ",q->info);
        }
    }
}

void insert_in_sorted_ll(struct node **start,int num){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node *q;
    struct node *prev;
    temp->info=num;
    if(*start==NULL || (*start) -> info >num){
        temp->next=*start;
        *start=temp;
    }else{
        for(q=*start;q!=NULL && q->info < num;prev=q,q=q->next);
        temp->next=q;
        prev->next=temp;
        
    }
}

void sorting(struct node **start){
    struct node *p,*q;
    q=*start;
    if(q==NULL){
        return;
    }
    for(;q->next!=NULL;q=q->next){
        for(p=q->next;p!=NULL;p=p->next){
            if(q->info>p->info){
                int k=q->info;
                q->info=p->info;
                p->info=k;
            }
        }
    }
}

void reverse_LL(struct node **start){
    struct node *p1,*p2,*p3;
    if(*start==NULL || (*start)->next==NULL){
        return;
    }
    p1=*start;
    p2=p1->next;
    p3=p2->next;
    p1->next=NULL;
    while(p3!=NULL){
        p2->next=p1;
        p1=p2;
        p2=p3;
        p3=p3->next;
    }
    p2->next=p1;
    *start=p2;
}

int main(){

    int a,n;
    struct node *n1=NULL;

    int k=0;
    while(k!=1){
        printf("\n ____________________________________________________________________\n\n");
        printf("Press 1 to insert at begining\n");
        printf("Press 2 to insert at the end\n");
        printf("Press 3 to insert after an element\n");
        printf("Print 4 to insert at any element\n");
        printf("Print 5 to del element from the begining\n");
        printf("Print 6 to del element from the end\n");
        printf("Print 7 to Del a particular element\n");
        printf("Print 8 to Del a particular element from the position\n");
        printf("Press 9 to search and del the element\n");
        printf("Press 10 to count the no.of nodes\n");
        printf("Press 11 to add in the sorted linked list\n");
        printf("Press 12 to sort the Linked list\n");
        printf("Press 13 to reverse the Linked list\n");
        printf("Press 14 to display\n");
        printf("Press any key to exit\n\n");
        int q=0;
        printf("Enter choice: ");
        scanf("%d",&q);
        printf("\n");
        if(q==1){
            printf("Enter the number to add in the linked list: ");
            scanf("%d",&a);
            insertion_begining(&n1,a);
        }else if(q==2){
            printf("Enter the number to add in the linked list: ");
            scanf("%d",&a);
            insertion_end(&n1,a);
        }else if(q==3){
            int b;
            printf("Enter the element after which to insert: ");
            scanf("%d", &b);

            printf("Enter the number to insert: ");
            scanf("%d", &a);
            insertion_aft_ele(&n1,b,a);
        }else if(q==4){
            int pos,num;
            printf("Enter the position you want to add the data :");
            scanf("%d",&pos);
            printf("Enter the number to add: ");
            scanf("%d",&num);
            insertion_at_pos(&n1,pos,num);
        }else if(q==5){
            deletion_begining(&n1);
        }else if(q==6){
            deletion_end(&n1);
        }else if(q==7){
            int w;
            printf("Enter the element to del: ");
            scanf("%d",&w);
            deletion_ele(&n1,w);
        }else if(q==8){
            int e;
            printf("Enter the position to del: ");
            scanf("%d",&e);
            deletion_ele_pos(&n1,e);
        }else if(q==9){
            int y;
            printf("Enter the element to search and del: ");
            scanf("%d",&y);
            deletion_ele(&n1,y);
        }else if(q==10){
            count(n1);
            printf("\n\n");
        }
        else if(q==11){
            int y;
            printf("Enter the element to add: ");
            scanf("%d",&y);
            insert_in_sorted_ll(&n1,y);
        }else if(q==12){
            sorting(&n1);
        }else if(q==13){
            reverse_LL(&n1);
        }
        else if(q==14){
            print(n1);
            printf("\n\n");
        }
        else{
            k=1;
            break;
        }
    }

    return 0;
}