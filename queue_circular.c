#include<stdio.h>

int f=-1,r=-1;
int queue[10];
int max=10; 

void enqueue(int val,int queue[]){
    if(f==-1 && r==max-1 || r+1==f){
        printf("Overflow");
        return  ;
    }else if(f==-1){
        f=r=0;
    }else if(r==max-1){
        r=0;
    }else{
        r++;
    }
    queue[r]=val;
}

int dequeue(int queue[]){
    int val;
    if(f==-1){
        printf("Underflow");
        return -1;
    }else if(f==r){
        val=queue[f];
        r=f=-1;
    }else if(f==max-1){
        val=queue[f];
        f=0;
    }else{
        val=queue[f];
        f++;
    }
    return (val);
}