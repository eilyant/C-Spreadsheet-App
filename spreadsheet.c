#include "spreadsheet.h"
#include "ordering.h"
#include "data.h"
#include "calc.h"
#include <stdio.h>
#include <stdlib.h>



// Global variables
int studentCount = 0;  // Initialize studentCount to 0
Student *students = NULL;  // Initialize students as NULL
int currentSortMethod = 1;  // Default sort method is by Student ID
// Global variables for grade thresholds
int gradeA = 80;
int gradeB = 70;
int gradeC = 60;
int gradeD = 50;
// Comparison function declarations
int compareByID(const void *a, const void *b);
int compareByLastName(const void *a, const void *b);
int compareByExamGrade(const void *a, const void *b);
int compareByTotalGrade(const void *a, const void *b);

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Spreadsheet App!\n");
    printf("1. Display Spreadsheet\n");
    printf("2. Show Grade Histogram\n");
    printf("3. Sort the Data\n");
    printf("4. Update Last Name\n");
    printf("5. Update Exam Grade\n");
    printf("6. Adjust Grade Mapping\n");
    printf("7. Remove a Student\n");
    printf("8. Exit\n");
    printf("Please select an option: ");
}



// Function to display the spreadsheet, applies the current sorting method
void displaySpreadsheet() {
    // Apply the current sorting method before displaying the spreadsheet
    switch (currentSortMethod) {
        case 1:
            sortByID(students, studentCount);  // Default: Sort by Student ID
            break;
        case 2:
            sortByLastName(students, studentCount);  // Sort by Last Name (Ascending)
            break;
        case 3:
            sortByExamGrade(students, studentCount);  // Sort by Exam Grade (Descending)
            break;
        case 4:
            sortByTotalGrade(students, studentCount);  // Sort by Total Grade (Descending)
            break;
        default:
            sortByID(students, studentCount);  // Fallback to Student ID sorting
    }

    printf("ID     Last Name          First Name         A1   A2   A3   Mid  Exam  Total   Grade\n");
    printf("-----------------------------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-6d %-18s %-18s %-4d %-4d %-4d %-4d %-5d %-8.2f %-2c\n",
               students[i].studentID,
               students[i].lastName,
               students[i].firstName,
               students[i].A1,
               students[i].A2,
               students[i].A3,
               students[i].midterm,
               students[i].exam,
               students[i].totalGrade,
               students[i].letterGrade);
    }
}
// Function to show histogram of grade distribution
void showHistogram() {
    int gradeCounts[5] = {0};  // A, B, C, D, F
    for (int i = 0; i < studentCount; i++) {
        switch (students[i].letterGrade) {
            case 'A': gradeCounts[0]++; break;
            case 'B': gradeCounts[1]++; break;
            case 'C': gradeCounts[2]++; break;
            case 'D': gradeCounts[3]++; break;
            case 'F': gradeCounts[4]++; break;
        }
    }

    // Function to print a line of stars corresponding to the count of each grade
    printf("Grade Distribution:\n");

    printf("A: ");
    for (int i = 0; i < gradeCounts[0]; i++) {
        printf("*");
    }
    printf("\n");

    printf("B: ");
    for (int i = 0; i < gradeCounts[1]; i++) {
        printf("*");
    }
    printf("\n");

    printf("C: ");
    for (int i = 0; i < gradeCounts[2]; i++) {
        printf("*");
    }
    printf("\n");

    printf("D: ");
    for (int i = 0; i < gradeCounts[3]; i++) {
        printf("*");
    }
    printf("\n");

    printf("F: ");
    for (int i = 0; i < gradeCounts[4]; i++) {
        printf("*");
    }
    printf("\n");
}







void hault(){
     printf("\nPress 'c' or 'C' to continue ");
    char c;
    while ((c = getchar()) != 'c' && c != 'C') {
        // Wait for the user to press 'c' or 'C'
    }
}

// Main function
int main() {
    int choice;

    readData();

    do {
        system("clear");  // Clears the screen
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySpreadsheet();
                hault();
                break;
            case 2:
                showHistogram();
                hault();
                break;
            case 3:
                sortMenu();
                hault();
                break;
            case 4:
                updateLastName();
                hault();
                break;
            case 5:
                updateExamGrade();
                hault();
                break;
            case 6:
                adjustGradeMapping();
                hault();
                break;
            case 7:
                removeStudent();
                break;
            case 8:
                printf("Goodbye and thanks for using our spreadsheet app!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 8);

    free(students);
    return 0;
}