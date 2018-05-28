/*
 * Filename: exercise16setA1.c
 * Created Date: Sunday, May 27th 2018, 8:02:47 pm
 * Author: Vrushab Bayas
 * @description
 * Create a structure student(roll no,name,marks of 3 sub,percentage).
 * Accept details of n students and write a menu driven program to perform the following operation
 * i)search ii)Modify iii)Display iv)Display students having percentage>=__ v)Display student with max percentage.
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//Student structure
typedef struct student
{
    char sName[50];
    int iRollNo;
    float fPercentage;
    int marks[3];

} STUD, *PSTUD;
//All function declarations
void acceptStudentInformation(PSTUD, int);
void displayAllStudents(PSTUD, int);
void search(PSTUD, char *, int);
//entry point function
int main()
{
    int iSize = 0;
    PSTUD sPtr = NULL;
    int choice;
    char name[20];
    printf("enter the number of students in school :");
    scanf("%d", &iSize);

    sPtr = (PSTUD)malloc(iSize * sizeof(STUD));

    acceptStudentInformation(sPtr, iSize);

    do
    {

        printf("#########################################\n");
        printf("1)Search\n");
        printf("2)Modify\n");
        printf("3)Display All Students \n");
        printf("4)Display All Stduents having percenage>__? \n");
        printf("5)Students with max Percentage\n");
        printf("6)Exit\n");
        printf("###########################################\n");
        printf("Enter your choice\n\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the name to search:");
            scanf("%s", name);
            search(sPtr, name, iSize);
            break;
        case 3:
            displayAllStudents(sPtr, iSize);
            break;
        case 6:
            exit(0);
        }
    } while (choice != 6);
}

void acceptStudentInformation(PSTUD sPtr, int iCount)
{
    int i = 0, j = 0;

    if ((sPtr == NULL) || (iCount <= 0))
    {
        printf("Memory not allocated..!\n");
        return;
    }
    printf("Enter information related to students:\n");

    for (i = 0; i < iCount; i++)
    {
        printf("Enter information of student %d :\n", i + 1);
        printf("Enter the Name:\n");
        scanf("%s", sPtr[i].sName);
        printf("Enter the roll Number:\n");
        scanf("%d", &sPtr[i].iRollNo);
        printf("Enter the Marks for each subject:\n");
        for (j = 0; j < 3; j++)
        {
            printf("Enter the mark for subject %d :\n", j + 1);
            scanf("%d", &(sPtr[i].marks[j]));
        }
    }
}

void displayAllStudents(PSTUD sPtr, int iCount)
{
    int i = 0, j = 0;
    printf("All students from school\n");
    for (i = 0; i < iCount; i++)
    {
        printf("Student name:%s\n", sPtr[i].sName);
        printf("Student Roll No:%d\n", sPtr[i].iRollNo);
        printf("Marks of the subjects:\n");
        for (j = 0; j < 3; j++)
        {
            printf("Marks of subject %d  :%d\n", j + 1, sPtr[i].marks[j]);
        }
        printf("\n");
    }
}

void search(PSTUD sPtr, char name[], int iCount)
{
    int i = 0;
    for (i = 0; i < iCount; i++)
    {
        if (strcmp(name, sPtr[i].sName) == 0)
        {
            printf("Match found \n");
            return;
        }
        else
        {
            printf("Match not found..!\n");
        }
    }
}