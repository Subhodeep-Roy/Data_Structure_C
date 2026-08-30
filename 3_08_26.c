#include<stdio.h>
#include<stdlib.h>

int del(int *arr,int size,int w){

    printf("\n\ndeleting ..........\n\n");

    for(int i=w;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    arr=realloc(arr,(size - 1) * sizeof(int));
    size--;

    printf("\n The new array :");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    
}

int add(int *arr,int size,int w,int n){
    printf("\nThe element is not found\n");
    printf("Enter the index to insert the element: ");
    scanf("%d",&w);
    printf("\nadding ...........\n\n");
    arr=realloc(arr,(size + 1) * sizeof(int));
    size++;
    for(int i=size;i>=w;i--){
        if(i==w){
            arr[i]=n;
        }else{
        arr[i]=arr[i-1];  
        }
    }

    printf("\n The new array :");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int *arr;
    arr=(int *)malloc(8*sizeof(int));
    arr[0]=1; arr[1]=2; arr[2]=3; arr[3]=54; arr[4]=6; arr[5]=745; arr[6]=3967; arr[7]=890;
    int size=8;

    int n;
    printf("Enter the number to search: ");
    scanf("%d",&n);
    int k=0,w=0;
    
    for(int i=0;i<size;i++){
        if(arr[i]==n){
            printf("\nThe element is found in the index: %d",i);
            w=i;
            k=1;
            break;
        }
    }

    if(k==0){
        add(arr,size,w,n);
    }
    else if(k==1){
        del(arr,size,w);        
    }

    free(arr);

    return 0;
}