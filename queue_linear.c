#include<stdio.h>

int f=-1,r=-1,max=10;              //global declaration
int queue[10];

void enqueue(int ele){
    if(r==max-1){
        printf("Overflow");
    }else{
        if(f==-1){
            f=0;
        }
        queue[++r]=ele;
    }
}

int dequeue(void){
    int val;
    if(f==-1){
        printf("Underflow");
    }else{
        val=queue[f];
        f++;
    }

    return val ;
}

void display(int queue[]){
    printf("\nQueue: ");
    for(int i=f;i<=r;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){

    enqueue(10);
    enqueue(20);
    display(queue);
    printf("deleted element : %d ",dequeue());
    enqueue(30);
    enqueue(40);
    display(queue);
    printf("deleted element : %d ",dequeue());
    display(queue);
    return 0;
}