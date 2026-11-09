#include<stdio.h>

// INPUT RESTRICTED
// |__
// |   INSERT RIGHT
// |__ 
// |   DELETE LEFT
// |___
//     DELETE RIGHT

// OUTPUT RESTRICTED
// |__
// |   INSERT LEFT
// |__ 
// |   INSERT RIGHT
// |___
//     DELETE LEFT

int queue[10];
int max=10;
int left=-1;
int right=-1;

void insert_right(int val,int queue[]){
    if(left==0 && right==max-1 || right+1==left){
        printf("Overflow");
        return;
    }else if(left==-1){
        left=right=0;
    }else if (right==max-1)
    {
        right=0;
    }else{
        right++;
    }
    queue[right]=val;
}

void insert_left(int val,int queue[]){
    if(left==0 && right==max-1|| right+1==left){
        printf("Overflow");
        return;
    }else if(left==-1){
        left=right=0;
    }else if(left==0){
        left=max-1;
    }else{
        left--;
    }
    queue[left]=val;
}

int del_left(int queue[]){
    int val;
    if(left==-1){
        printf("underflow");
    }else if(right==left){
        val=queue[left];
        left=right=-1;
    }else if(left==max-1){
        val=queue[left];
        left=0;
    }else{
        val=queue[left];
        left++;
    }
    return(val);
}

int del_right(int queue[]){
    int val;
    if(left==-1){
        printf("Underflow");
        return val; 
    }else if(right==left){
        val=queue[right];
        right=left=-1;
    }else if(right==0){
        val=queue[right];
        right=max-1;
    }else{
        val=queue[right];
        right--;
    }
    return (val);
}