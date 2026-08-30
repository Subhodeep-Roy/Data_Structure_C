#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct std{
    int roll;
    char name[50];
    char gender;
    int marks;
    char grade;
};

void func(struct std *s1,int n){

    printf("\nStudent Data: \n\n");
    for(int i=0;i<n;i++){
        printf("Roll : %d\n",s1[i].roll);
        printf("Name :%s\n",s1[i].name);
        printf("Gender: %c\n",s1[i].gender);
        printf("Marks : %d\n",s1[i].marks);
        if(s1[i].marks>=90){
            s1[i].grade='O';
        }
        else if(s1[i].marks>=80 && s1[i].marks<90){
            s1[i].grade='E';
        }
        else if(s1[i].marks>=70 && s1[i].marks<80){
            s1[i].grade='A';
        }
        else if(s1[i].marks>=60 && s1[i].marks<70){
            s1[i].grade='B';
        }
        else if(s1[i].marks>=50 && s1[i].marks<60){
            s1[i].grade='C';
        }
        else if(s1[i].marks>=40 && s1[i].marks<50){
            s1[i].grade='D';
        }
        else{
            s1[i].grade='F';
        }
        printf("Grade: %c",s1[i].grade);
        printf("\n\n");
    }
}

int countf(struct std *s1,int n){
    int c=0;

    for(int i=0;i<n;i++){
        if(s1[i].grade=='F'){
            c++;
        }
    }
    return c;
}

int main(){

    int n;
    printf("Enter no.of Students to be entered: ");
    scanf("%d",&n);

    struct std *s1=malloc(n * sizeof(struct std));
    if(s1==NULL){
        printf("Memory not allocated");
        exit(0);
    }

    for(int i=0;i<n;i++){
        fflush(stdin);
        printf("Enter name: ");
        scanf("%[^\n]s",s1[i].name);
        printf("Enter Roll : ");
        scanf("%d",&s1[i].roll);
        printf("Enter Gender: ");
        scanf(" %c",&s1[i].gender);
        printf("Enter marks: ");
        scanf("%d",&s1[i].marks);
        printf("\n\n");
    }

    func(s1,n);
    printf("\nNo.of Students failed: %d",countf(s1,n));

    free(s1);

    printf("\nNo.of Students failed: %d",countf(s1,n));

    return 0;
}