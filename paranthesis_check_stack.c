#include<stdio.h>
#include<string.h>

int max=100,top=-1;
char stack[100];
char val='N';

void push(char ele){
    if(top == max-1){
        printf("Overflow");
    }else{
        stack[++top]=ele;
    }
}

char pop(void){
    if(top == -1){
        printf("Underflow");
    }else{
        val=stack[top--];
        return val;
    }
}

int main(){
    char s[] = {'(',')','\0'};
    int valid=1;
    char ch;

    for(int i=0;i<strlen(s);i++){
        if(s[i]=='('|| s[i]=='{'|| s[i]=='['){
            push(s[i]);
        }else if(s[i]==')'|| s[i]=='}'|| s[i]==']'){
            if(top==-1){
                valid=0;
            }else{
                ch=pop();

                if((s[i] == ')' && ch != '(') ||
                    (s[i] == '}' && ch != '{') ||
                    (s[i] == ']' && ch != '[')){
                        valid = 0;
                    }
            }
        }
    }

    if(top!= -1){
        valid=0;
    }

    if(valid == 0){
        printf("NOT VALID");
    }else{
        printf("VALID");
    }
    

    return 0;
}