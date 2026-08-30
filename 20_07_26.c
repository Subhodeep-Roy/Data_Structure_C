#include<stdio.h>

int swapa(int *a,int*b){
    int c=*a;
    *a=*b;
    *b=c;
    printf("A = %d",*a);
    printf("\nB = %d",*b);
    return 0;
}

int swapv(int a,int b){
    int temp=a;
    a=b;
    b=temp;
    printf("A = %d",a);
    printf("\nB = %d",b);
    return 0;
}

int com(int *a,int *b){
    if(*a>*b){
        printf("%d is Greater",*a);
    }
    else if(*a<*b){
        printf("%d is Greater",*b);
    }
    else{
        printf("Both are Equal");
    }
    return 0;
}

int main(){

    int a=10,b=20,l=1;
    printf("A = %d",a);
    printf("\nB = %d",b);
    printf("\nEnter your Choice\n");
    printf("1. Call by Address\n");
    printf("2. Call by Value\n");
    printf("3. Compare Values\n");
    printf("4. To quit\n \n");

    while(l>0){
        int k;
        printf("\nEnter your choice: ");
        scanf("%d",&k);
        switch(k){
            case 1:
                swapa(&a,&b);
                break;
            case 2:
                swapv(a,b);
                break;
            case 3:
                com(&a,&b);
                break;
            case 4:
                l=0;
                break;
            default:
                printf("Invalid Choice");
                break;
        }
    }

    return 0;
}