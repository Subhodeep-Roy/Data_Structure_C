#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *q=head;
    struct ListNode *prev;
    struct ListNode *c=head;
    int k=0;
    for(;c!=NULL;c=c->next){
        k++;
    }

    int j=k-n;

    if(head==NULL){
        return head;
    }else if(n==n){
        head=head->next;
    }else{
        for(int i=1;i<j;i++){
            prev=q;
            q=q->next;
            if(q==NULL){
                return 0;
            }
        }
        prev->next=q->next;
        free(q);
    }

    return(head);
}

void insert_end(struct ListNode* mergeTwoLists,int num){
    struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val=num;
    temp->next=NULL;
    struct ListNode *q=mergeTwoLists;
    
    if(mergeTwoLists==NULL){
        temp->next=mergeTwoLists;
        mergeTwoLists=temp;
    }else{
        for(;q->next!=NULL;q=q->next);
        q->next=temp;
    }
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *q=list1;
    struct ListNode *p=list2;
    struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head=NULL;
    
    while(q!=NULL && p!=NULL){
        if(q->val>p->val){
            struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val=p->val;
            temp->next=NULL;
            struct ListNode *z=head;
            
            if(head==NULL){
                temp->next=head;
                head=temp;
            }else{
                for(;z->next!=NULL;z=z->next);
                z->next=temp;
            }
            p=p->next;
        }else{
            struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
            temp->val=q->val;
            temp->next=NULL;
            struct ListNode *x=head;
            
            if(head==NULL){
                temp->next=head;
                head=temp;
            }else{
                for(;x->next!=NULL;x=x->next);
                x->next=temp;
            }
            q=q->next;
        }
    }
    while(p!=NULL){
        struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val=p->val;
        temp->next=NULL;
        struct ListNode *c=head;
        
        if(head==NULL){
            temp->next=head;
            head=temp;
        }else{
            for(;c->next!=NULL;c=c->next);
            c->next=temp;
        }
        p=p->next;
    }
    while(q!=NULL){
        struct ListNode *temp=(struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val=q->val;
        temp->next=NULL;
        struct ListNode *v=head;
        
        if(head==NULL){
            temp->next=head;
            head=temp;
        }else{
            for(;v->next!=NULL;v=v->next);
            v->next=temp;
        }
        q=q->next;
    }
    return head;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* q=head->next;
    struct ListNode* prev=head;

    if(head==NULL){
        return head;
    }

    while(q!=NULL){
        if(prev->val=q->val){
            prev->next=q->next;
            free(q);
            q=prev->next;
        }else{
            prev=q;
            q=q->next;
        }
    }
    return head;
}

void deleteNode(struct ListNode* node) {
    struct ListNode *q= node->next;
    struct ListNode *prev=node;
    struct ListNode *temp;
    temp->val=q->val;
    q->val=prev->val;
    prev->val=temp->val;
    prev->next=q->next;
    free(q);
}

struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode* c=head;
    struct ListNode* q=head->next;
    struct ListNode* prev=head;
    int n=0;
    for(;c->next!=NULL;c=c->next){
        n++;
    }
    if(n!=0){
        if(n%2==0){
            n=n/2;
        }else{
            n=((n/2)+1);
        }
        for(int i=1;i<n;i++){
            prev=q;
            q=q->next;
        }
        prev->next=q->next;
        free(q);
    }else{
        head=head->next;
    }

    return head;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *p1=head;
    struct ListNode *p2=p1->next;
    struct ListNode *p3=p2->next;

    if(head==NULL || head->next==NULL){
        return head;
    }

    p1->next=NULL;
    while(p3!=NULL){
        p2->next=p1;
        p1=p2;
        p2=p3;
        p3=p3->next;
    }
    p2->next=p1;
    head=p2;

    return head;
}

struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL){
        return head;
    }
    struct ListNode *even_start=NULL;
    struct ListNode*even=NULL;
    struct ListNode*odd_start=NULL;
    struct ListNode*odd=NULL;
    struct ListNode *p=head;
    int k=1;
    // p=head;

    while(p!=NULL){
        if(((k)%2==0) && even_start==NULL){
            even=even_start=p;
        }else if((k)%2==0){
            even->next=p;
            even=p;
        }else if(((k)%2!=0) && odd_start==NULL){
            odd=odd_start=p;
        }else{
            odd->next=p;
            odd=p;
        }
        k++;
        p=p->next;
    }
    odd->next=even_start;
    even->next=NULL;
    

    return head;
}

struct ListNode* removeNodes(struct ListNode* head) {
   
    struct ListNode *p1,*p2,*p3;
    p1=head;                         //reverse
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
    head=p2;
    struct ListNode *temp,*p;
    p=p2->next;

    while(p!=NULL){
        if(p2->val>p->val){
            temp=p;
            p2->next=p->next;
            free(temp);
            p=p2->next;
            
        }else{
            p2=p;
            p=p->next;
        }
    }

    if(head==NULL||head->next==NULL){
        return head;
    }else if(head->next->next==NULL){
        struct ListNode *q,*p;
        p=head;
        q=head->next;

        q->next=p;
        p->next=NULL;
        head=q;
        
    }else{
        struct ListNode *p6,*p7,*p8;
        p6=head;                         //reverse again
        p7=p6->next;
        p8=p7->next;
        p6->next=NULL;
        while(p8!=NULL){
            p7->next=p6;
            p6=p7;
            p7=p8;
            p8=p8->next;
        }
        p7->next=p6;
        head=p7;
    }
    return head;
}

int main(){


    return 0;
}