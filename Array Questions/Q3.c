#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[30];
    int age;
    int rollno;
    float percentage;
};
int main(){
    struct Student student1;
    struct Student* ptr = &student1;
    printf("Enter the details of student:\n");

    printf("Enter the name of student:");
    fgets(ptr->name,30,stdin);      //ptr->name is an array thus also a alias for pointer to it is ptr->name
    printf("Enter the age of student:");
    scanf("%d",&ptr->age);
    printf("Enter the roll number of student:");
    scanf("%d",&ptr->rollno);
    printf("Enter the percentage of student:");
    scanf("%f",&ptr->percentage);

    printf("The details of student is:\n");
    printf("Name:%s",ptr->name);
    printf("Age:%d\n",ptr->age);
    printf("Rollno:%d\n",ptr->rollno);
    printf("Percentage:%.1f%%",ptr->percentage);

    return 0;
}