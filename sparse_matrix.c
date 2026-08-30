#include<stdio.h>
#include<stdlib.h>

int print(int **arr,int r,int c){
    printf("\n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int transpose(int **arr,int row,int column){
    int c=0;
    for(int i=0;i<3;i++){                             //no.of non-zero element
        for(int j=0;j<3;j++){
            if(arr[i][j]!=0){
                c++;
            }
        }
    }

    int **arr_2;
    arr_2=(int **)malloc((c+1)*sizeof(int *));
    for(int i=0;i<c+1;i++){
        arr_2[i]=(int *)malloc(3*sizeof(int));
    }
    arr_2[0][0] = 3;
    arr_2[0][1] = 3;
    arr_2[0][2] = c;
    int w=0;
    for(int i=0;i<3;i++){                           // sparse matrix ----> triplet form
        for(int j=0;j<3;j++){
            if(arr[i][j]!=0){
                arr_2[w+1][0] = i;
                arr_2[w+1][1]= j;
                arr_2[w+1][2]=arr[i][j];
                w++;
            }
        }
    }
    printf("\n Triplet : \n");
    print(arr_2, c+1, 3);                          //printing the sparse matrix


    for(int i=1;i<c+1;i++){                               //transpose
        //for(int j=0;j<3;j++){
            int k= arr_2[i][0];
            arr_2[i][0]=arr_2[i][1];
            arr_2[i][1]=k;
        //}
    }
    print(arr_2,c+1,3);

    for(int i=1;i<c+1;i++){                                 //order by row(transpose)
        for(int j=i;j<c+1;j++){
            if(arr_2[i][0]>arr_2[j][0]){
                int t1=arr_2[i][0];
                arr_2[i][0]=arr_2[j][0];
                arr_2[j][0]=t1;

                t1=arr_2[i][1];
                arr_2[i][1]=arr_2[j][1];
                arr_2[j][1]=t1;

                t1=arr_2[i][2];
                arr_2[i][2]=arr_2[j][2];
                arr_2[j][2]=t1;

            }
        }
    }

    printf("\nTranspose: \n");
    print(arr_2,c+1,3);                        //printing the transpose matrix

    free(arr);
    free(arr_2);
}

int main(){
    int **arr;
    arr=(int **)malloc((3+1)*sizeof(int *));
    for(int i=0;i<3;i++){
        arr[i]=(int *)malloc((3+1)*sizeof(int));
    }
    arr[0][0] = 1; arr[0][1] = 9; arr[0][2] = 0;
    arr[1][0] = 0; arr[1][1] = 2; arr[1][2] = 0;
    arr[2][0] = 7; arr[2][1] = 0; arr[2][2] = 3;
    printf("The 2d Array : \n");
    print(arr, 3, 3);                                           //printing the array

    transpose(arr,3,3);

    return 0;
}