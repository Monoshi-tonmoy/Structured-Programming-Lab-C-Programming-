#include <stdio.h>
#include <string.h>

int num_of_courses=5;
int num_of_students=2;

struct student{
    int id;
    char name[20];
    struct course{
        char course_id[20];
        char sub_name[30];
        float credit;
        float achieved_mark;
        float grade;
    };
    struct course courses[5];
};

float cgpa_counter(struct student a)
{
    float cgpa;
    int i;
    float creditM=0.0,total_credit=0.0;
    for(i=0;i<num_of_courses;i++){
        creditM=creditM+(a.courses[i].grade*a.courses[i].credit);
        total_credit=total_credit+a.courses[i].credit;
    }
    cgpa=(creditM/total_credit);
    return cgpa;
}

int main()
{
    struct student s[num_of_students];
    printf("Taking input as first student's information");
    int i,j;
    for(i=0;i<2;i++){
        char name[50];
        printf("Enter student %d's information:\n",i+1);
        printf("Student's ID:\n");
        scanf("%d",&s[i].id);
        fflush(stdin);
        printf("Student's Name:\n");
        gets(name);
        strcpy(s[i].name,name);
        printf("Enter Id:%d\tNames:%s's course information\n",s[0].id,s[0].name);
        for(j=0;j<5;j++){
            char course_id[20],subject[30];
            printf("Give course %d's information:\n",j+1);
            printf("Course Id:");
            gets(course_id);
            fflush(stdin);
            strcpy(s[i].courses[j].course_id,course_id);
            printf("Course name:");
            gets(subject);
            fflush(stdin);
            strcpy(s[i].courses[j].sub_name,subject);
            printf("Course Credit:");
            scanf("%f",&s[i].courses[j].credit);
            printf("Achieved mark in this course:");
            scanf("%f",&s[i].courses[j].achieved_mark);
            fflush(stdin);
            if(s[i].courses[j].achieved_mark>=80 && s[i].courses[j].achieved_mark<=100){
                s[i].courses[j].grade=4.0;
            }
            else if(s[i].courses[j].achieved_mark>=75 && s[i].courses[j].achieved_mark<80){
                s[i].courses[j].grade=3.75;
            }
            else if(s[i].courses[j].achieved_mark>=70 && s[i].courses[j].achieved_mark<75){
                s[i].courses[j].grade=3.50;
            }
            else if(s[i].courses[j].achieved_mark>=65 && s[i].courses[j].achieved_mark<70){
                s[i].courses[j].grade=3.25;
            }
            else if(s[i].courses[j].achieved_mark>=60 && s[i].courses[j].achieved_mark<65){
                s[i].courses[j].grade=3.00;
            }
            else if(s[i].courses[j].achieved_mark>=55 && s[i].courses[j].achieved_mark<60){
                s[i].courses[j].grade=2.75;
            }
            else if(s[i].courses[j].achieved_mark>=50 && s[i].courses[j].achieved_mark<55){
                s[i].courses[j].grade=2.50;
            }
            else if(s[i].courses[j].achieved_mark>=45 && s[i].courses[j].achieved_mark<50){
                s[i].courses[j].grade=2.25;
            }
            else if(s[i].courses[j].achieved_mark>=40 && s[i].courses[j].achieved_mark<45){
                s[i].courses[j].grade=2.00;
            }
            else if(s[i].courses[j].achieved_mark>=0 && s[i].courses[j].achieved_mark<40){
                s[i].courses[j].grade=0.00;
            }
        }
    }
    for(i=0;i<num_of_students;i++){
        printf("%s's Cgpa is %f",s[i].name,cgpa_counter(s[i]));
    }

}


