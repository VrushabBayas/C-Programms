/*
 * Filename: EmployeeStructure.c
 * Path: C-Programms/Structures
 * Created Date: Tuesday, May 29th 2018, 9:14:48 am
 * Author: Vrushab Bayas
 * @(description):perform following opeatiomns on the employee structure
 * i)Search by name II)search by Id III)Display all  IV)Having salary >__ V)Having max salary
 * Copyright (c) 2018 Your Company
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
//Employee structure

typedef struct employee
{
    char eName[50];
    int id;
    float fSalary;
} EMP, *PEMP;

//Functuion declarations
void AcceptEmpInfo(PEMP, int);
void DisplayEMPInfo(PEMP, int);
void SearchByID(PEMP, int, int);
void SearchByName(PEMP, char *, int);
void Salary(PEMP, float, int);
void MaxSalary(PEMP, int);

//Entry point function

int main()
{
    int iCount = 0;
    PEMP ePtr = NULL;
    int choice = 0;
    char name[50];
    int ID = 0;
    float salary = 0.0;
    printf("How many employies in the compony..?:");
    scanf("%d", &iCount);

    ePtr = (PEMP)malloc(iCount * sizeof(EMP));
    if (ePtr == NULL)
    {
        printf("Memory not allocated..!\n");
    }
    AcceptEmpInfo(ePtr, iCount);

    do
    {
        printf("#################################################33\n\n");
        printf("1)Display\n");
        printf("2)Search by Name\n");
        printf("3)Search by ID\n");
        printf("4)Salary greater than..?\n");
        printf("5)Max salary\n");
        printf("#####################################################\n\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            DisplayEMPInfo(ePtr, iCount);
            break;
        case 2:
            printf("Enter name to search:");
            scanf(" %[^'\n']s", name);
            SearchByName(ePtr, name, iCount);
            break;
        case 3:
            printf("Enter ID to search:");
            scanf("%d", &ID);
            SearchByID(ePtr, ID, iCount);
            break;
        case 4:
            printf("enter salary:");
            scanf("%f", &salary);
            Salary(ePtr, salary, iCount);
            break;
        case 5:
            MaxSalary(ePtr, iCount);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice");
        }
    } while (choice != 6);
}

void AcceptEmpInfo(PEMP ePtr, int iCount)
{
    int i = 0;
    for (i = 0; i < iCount; i++)
    {
        printf("Enter the Information of %d employee\n\n", i + 1);
        printf("Enter the name of employee:\n");
        scanf(" %[^'\n']s ", ePtr[i].eName);
        printf("enter the Id of an employee:\n");
        scanf("%d", &ePtr[i].id);
        printf("enter the salary of the employee:\n");
        scanf("%f", &ePtr[i].fSalary);
    }
}

void DisplayEMPInfo(PEMP ePtr, int iCount)
{
    int i = 0;
    for (i = 0; i < iCount; i++)
    {
        printf("Information of Emp %d\n", i + 1);
        printf("Employee Name: %s\n", ePtr[i].eName);
        printf("ID\t\t: %d\n", ePtr[i].id);
        printf("Salary\t: %f\n", ePtr[i].fSalary);
    }
}
void SearchByName(PEMP ePtr, char name[], int iCount)
{
    int i = 0;
    for (i = 0; i < iCount; i++)
    {
        if (strcmp(name, ePtr[i].eName) == 0)
        {
            printf("Employee Id :%d\n", ePtr[i].id);
            printf("Employee salary: %f\n", ePtr[i].fSalary);
        }
        else if (i == iCount)
        {
            printf("Record  not found..!\n");
        }
    }
}
void SearchByID(PEMP ePtr, int Id, int iCount)
{
    int i = 0;
    for (i = 0; i < iCount; i++)
    {
        if (ePtr[i].id == Id)
        {
            printf("Employee Name: %s\n", ePtr[i].eName);
            printf("Employee salary: %f\n", ePtr[i].fSalary);
        }
        else if (i == iCount)
        {
            printf("Record  not found..!\n");
        }
    }
}
void MaxSalary(PEMP ePtr, int iCount)
{
    float max = 0.0;
    int i = 0;
    for (i = 0; i < iCount; i++)
    {
        if (ePtr[i].fSalary > max)
        {
            max = ePtr[i].fSalary;
        }
    }
    printf("Max Salary is : %f  \n\n", max);
}
void Salary(PEMP ePtr, float salary, int iCount)
{
    int i = 0;
    for (i = 0; i < iCount; i++)
    {
        if (ePtr[i].fSalary > salary)
        {
            printf("Salary greater than   %f is :\t %f  \n\n", salary, ePtr[i].fSalary);
        }
        else if (i == iCount)
        {
            printf("Record  not found..!\n");
        }
    }
}