#include "ordering.h"
#include "spreadsheet.h"  // Include this to access the Student structure
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern int currentSortMethod;
extern int studentCount;
extern Student *students;
// Sorting functions
void sortMenu() {
    int sortChoice;
    printf("Select a sort option:\n");
    printf("1. Student ID (Ascending)\n");
    printf("2. Last Name (Ascending)\n");
    printf("3. Exam Grade (Descending)\n");
    printf("4. Total Grade (Descending)\n");
    printf("Please select an option: ");
    scanf("%d", &sortChoice);

    switch(sortChoice) {
        case 1:
            currentSortMethod = 1;
            sortByID(students, studentCount);
            break;
        case 2:
            currentSortMethod = 2;
            sortByLastName(students, studentCount);
            break;
        case 3:
            currentSortMethod = 3;
            sortByExamGrade(students, studentCount);
            break;
        case 4:
            currentSortMethod = 4;
            sortByTotalGrade(students, studentCount);
            break;
        default:
            printf("Invalid option, returning to main menu.\n");
    }
}

// Sort by Student ID (default)
void sortByID(Student students[], int studentCount) {
    qsort(students, studentCount, sizeof(Student), compareByID);
}

int compareByID(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return studentA->studentID - studentB->studentID;
}

// Sort by Last Name (ascending)
void sortByLastName(Student students[], int studentCount) {
    qsort(students, studentCount, sizeof(Student), compareByLastName);
}

int compareByLastName(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return strcmp(studentA->lastName, studentB->lastName);
}

// Sort by Exam Grade (descending)
void sortByExamGrade(Student students[], int studentCount) {
    qsort(students, studentCount, sizeof(Student), compareByExamGrade);
}

int compareByExamGrade(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return studentB->exam - studentA->exam;  // Descending order
}

// Sort by Total Grade (descending)
void sortByTotalGrade(Student students[], int studentCount) {
    qsort(students, studentCount, sizeof(Student), compareByTotalGrade);
}

int compareByTotalGrade(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    if (studentB->totalGrade > studentA->totalGrade)
        return 1;
    else if (studentB->totalGrade < studentA->totalGrade)
        return -1;
    else
        return 0;
}
