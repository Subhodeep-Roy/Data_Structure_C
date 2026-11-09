#include<stdio.h>

int top=-1,max=5;

void push(int ele,int stack[]){                     //to push element 
    if(top == max-1){
        printf("Overflow");
    }else{
        stack[++top]=ele;
    }
}

int pop(int stack[]){                               //to pop element
    int value=-1;
    if(top==-1){
        printf("Underflow");
    }else{
        value=stack[top--];
    }
    return (value);
}

void print(int stack[]){                            //to display element
    printf("\n");
    printf("Stack:       ");
    for(int i=0;i<max;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

//RECURSION

int display(int stack[]){                     // to display the element
    int x;
    if(top==-1){
        return 0;
    }else{
        x=pop(stack);
        printf("%d ",x);
        display(stack);   
        push(x,stack);
    }
}

int display_rev(int stack[]){                     // to display the element
    int x;
    if(top==-1){
        return 0;
    }else{
        x=pop(stack);
        display_rev(stack);
        printf("%d ",x);              
        push(x,stack);
    }
}

int push_bottom(int ele,int stack[]){            // to add element at the bottom of the stack
    int x;
    if(top==-1){
        push(ele,stack);
    }else{
        x=pop(stack);
        push_bottom(ele,stack);
        push(x,stack);

    }
}

int reverse(int stack[]){                      //to reverse the stack
    int x;
    if(top==-1){
        return 0;
    }else{
        x=pop(stack);
        reverse(stack);
        push_bottom(x,stack);
    }
}

int insert_sorted_ele(int ele,int stack[]){           //to insert the element in a sorted order
    int x;
    if(top==-1 || ele>stack[top]){
        push(ele,stack);
    }else{
        x=pop(stack);
        insert_sorted_ele(ele,stack);
        push(x,stack);
    }
}

int sort(int stack[]){                           //to sort the stack
    int x;
    if(top==-1){
        return 0;
    }else{
        x=pop(stack);
        sort(stack);
        insert_sorted_ele(x,stack);
    }
}

int main(){
    int stack[max];
    // print(stack);
    int a =93,b=13,c=60;
    push(a,stack);
    // print(stack);
    push(b,stack);
    // print(stack);
    // printf("\nPoped element:       %d\n",pop(stack));
    // print(stack);
    push(c,stack);
    // print(stack);
    printf("Stack: ");
    display(stack);
    printf("\nReverse: ");
    display_rev(stack);
    printf("\nAdded from bottom in Stack: ");
    push_bottom(56,stack);
    display(stack);
    printf("\nReversed: ");
    reverse(stack);
    display(stack);
    printf("\nAdding a element: ");
    insert_sorted_ele(38,stack);
    display(stack);
    printf("\nSorted Stack: ");
    sort(stack);
    display(stack);
        
    return 0;
}

