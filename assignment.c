#include<stdio.h>
#include <stdbool.h>

//Linked List
// struct node {
//     int val;
//     struct node *next;
// };

// void swap_nodes(struct node *head,int a,int b){
//     struct node *q,*p,*prev1=NULL,*prev2=NULL;
//     if(head->val == a){
//         q=head;
//         for(p=head;p->val!=b;prev2=p,p=p->next);

//         struct node *temp=q->next;
//         head=p;
//         q->next=p->next;
//         p->next=temp;

//     }
//     else if(head->val == b){
//         p=head;
//         for(q=head;q->val!=a;prev1=q,q=q->next);

//         struct node *temp=p->next;
//         head=q;
//         p->next=q->next;
//         q->next=temp;
//     }else{
//         for(q=head;q->val!=a;prev1=q,q=q->next);
//         for(p=head;p->val!=b;prev2=p,p=p->next);

//         prev1->next=p;
//         prev2->next=q;
//         struct node *temp=q->next;
//         q->next=p->next;
//         p->next=temp;
//     }

//     return head;
// }

// void detectAndRemoveLoop(struct node *head) {

//     struct node *slow=head;
//     struct node *fast=head;

//     while(fast!=NULL && fast->next!=NULL) {

//         slow=slow->next;
//         fast=fast->next->next;

//         if(slow==fast)
//             break;
//     }

//     if(fast==NULL || fast->next==NULL)
//         return;

//     slow=head;

//     if(slow==fast) {
//         while(fast->next!=slow)
//             fast=fast->next;
//     }
//     else {
//         while(slow->next!=fast->next) {
//             slow=slow->next;
//             fast=fast->next;
//         }
//     }

//     fast->next=NULL;
// }

// void pallindrome(struct node *head){
//     struct node *p=head,*q;
//     int c=0;
//     for(;p!=NULL;p=p->next){
//         c++;
//     }
//     int arr[c],i=0;
//     for(q=head;q!=NULL;q=q->next){
//         arr[i]=q->val;
//         i++;
//     }
//     c=c-1;
//     while(i<c){
//         if(arr[i]!=arr[c]){
//             printf("Not Pallindrome");
//             return;
//         }
//         i++;
//         c--;
//     }
//     printf("Pallindrome");

// }

// struct node *reverse_group_ll(struct node *head,int n){
//     if(head->next==NULL || n<=1){
//         return head;
//     }else{
//         struct node *q=head,*p=head,*nxt=q->next,*nxt2=nxt->next;

//         for(int i=0;i<n;i++){
//             if(p==NULL){
//                 return head;
//             }
//             p=p->next;
//         }

//         q->next=p;
//         while(nxt2!=p){
//             nxt->next=q;
//             q=nxt;
//             nxt=nxt2;
//             nxt2=nxt2->next;
//         }
//         nxt->next=q;
        
//         return head;
//     }
// }

// struct node* separate_even_odd(struct node *head) {
//     struct node *evenHead = NULL, *evenTail = NULL;
//     struct node *oddHead = NULL, *oddTail = NULL;
//     struct node *p = head, *nxt;

//     while (p != NULL) {
//         nxt = p->next;
//         p->next = NULL;

//         if (p->val % 2 == 0) {
//             if (evenHead == NULL) {
//                 evenHead = evenTail = p;
//             } else {
//                 evenTail->next = p;
//                 evenTail = p;
//             }
//         } else {
//             if (oddHead == NULL) {
//                 oddHead = oddTail = p;
//             } else {
//                 oddTail->next = p;
//                 oddTail = p;
//             }
//         }

//         p = nxt;
//     }

//     if (evenHead == NULL)
//         return oddHead;

//     evenTail->next = oddHead;

//     return evenHead;
// }

// struct node* rearrange(struct node *head) {
//     if (head == NULL || head->next == NULL)
//         return head;

//     struct node *odd = head;
//     struct node *even = head->next;
//     struct node *evenHead = even;

//     while (even != NULL && even->next != NULL) {
//         odd->next = even->next;
//         odd = odd->next;

//         even->next = odd->next;
//         even = even->next;
//     }

//     odd->next = evenHead;

//     return head;
// }

// struct node* reverse(struct node *head) {
//     if (head == NULL || head->next == NULL) {
//         return head;
//     }

//     struct node *newhead = reverse(head->next);

//     head->next->next = head;
//     head->next = NULL;

//     return newhead;
// }

// void dif(struct node *head1,struct node*head2){
//     struct node *p=head1,*q=head2;
//     if(p==NULL && q==NULL){
//         printf("Same");
//         return;
//     }
//     for(;q!=NULL || p!=NULL;p=p->next,q=q->next){
//         if(p->val!=q->val){
//             printf("Different");
//             return;
//         }
//     }
    
//     if(q==NULL && p==NULL){
//         printf("Same");
//     }
//     else{
//         printf("Different");
//     }
// }

// int intersection(struct node *head1,struct node *head2){
//     struct node *q=head1,*p=head2;
//     int k=0;
//     for(;q!=NULL && p!=NULL;q=q->next,p=p->next){
//         if(q==p){
//             k=q->val;
//             return k;
//         }
//     }
//     return -1;
// }


//Tree
struct node {
    struct node *lchild;
    int info;
    struct node *rchild;
};

bool check(struct node*ptr1,struct node*ptr2){
    if(ptr1==NULL && ptr2==NULL){
        return true;
    }
    if(ptr1==NULL || ptr2==NULL){
        return false;
    }
    if(ptr1->info!=ptr2->info){
        return false;
    }

    return(check(ptr1->lchild,ptr2->lchild) && check(ptr1->rchild,ptr2->rchild));

}

struct node *m(struct node *ptr1,struct node *ptr2){
    if(ptr1==NULL && ptr2==NULL){
        return ptr2;
    }else{
        ptr2->info=ptr1->info;
        m(ptr1->lchild,ptr2->lchild);
        m(ptr1->rchild,ptr2->rchild);
    }
    return ptr2;
}

struct node* constructTree(int arr[], int n) {
    if(n == 0) {
        return NULL;
    }

    struct node *root = createNode(arr[0]);

    struct node *queue[100];
    int f = 0, r = 0;

    queue[r++] = root;

    int i = 1;

    while(i < n) {
        struct node *temp = queue[f++];

        // Create left child
        temp->lchild = createNode(arr[i++]);
        queue[r++] = temp->lchild;

        // Create right child
        if(i < n) {
            temp->rchild = createNode(arr[i++]);
            queue[r++] = temp->rchild;
        }
    }

    return root;
}