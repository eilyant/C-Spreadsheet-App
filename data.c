#include "data.h"
#include "spreadsheet.h"
#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int studentCount;
extern Student *students;
// Function to read student data from file
void readData() {
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        exit(1);
    }

    char buffer[256];
    studentCount = 0;

    // Count how many students are there, i.e., how many lines
    while (fgets(buffer, sizeof(buffer), file)) {
        studentCount++;
    }
    fclose(file);

    students = (Student *)malloc(studentCount * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    file = fopen("students.txt", "r");
    int counter = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        char tempLastName[50], tempFirstName[50];  // Temporary buffers for the names
        sscanf(buffer, "%d|%[^|]|%[^|]|%d|%d|%d|%d|%d",
               &students[counter].studentID,
               tempLastName,
               tempFirstName,
               &students[counter].A1,
               &students[counter].A2,
               &students[counter].A3,
               &students[counter].midterm,
               &students[counter].exam);
        strcpy(students[counter].lastName, tempLastName);
        strcpy(students[counter].firstName, tempFirstName);
        counter++;
    }

    fclose(file);
    calculateGrades(students, studentCount);
}

// Function to update last name of a student
void updateLastName() {
    // Display the current spreadsheet before prompting
    printf("Here is the current spreadsheet:\n");
    displaySpreadsheet();  // Show the spreadsheet so the user can see Student IDs

    int id;
    char newLastName[50];
    printf("\nEnter student ID to update last name: ");
    scanf("%d", &id);

    // Find the student with the given ID
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == id) {
            printf("Current name: %s %s\n", students[i].firstName, students[i].lastName);
            printf("Enter new last name: ");
            scanf("%s", newLastName);

            // Update the last name
            strcpy(students[i].lastName, newLastName);
            printf("Last name updated for student ID %d.\n", id);
            return;  // Exit the function after the update
        }
    }
    printf("Student ID not found.\n");  // If the student ID is not found
}

// Function to update exam grade of a student
void updateExamGrade() {
    // Display the current spreadsheet before prompting
    printf("Here is the current spreadsheet:\n");
    displaySpreadsheet();  // Show the spreadsheet so the user can see Student IDs

    int id, newGrade;
    printf("\nEnter student ID to update exam grade: ");
    scanf("%d", &id);

    // Find the student with the given ID
    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == id) {
            printf("Current exam grade for %s %s: %d\n", students[i].firstName, students[i].lastName, students[i].exam);
            printf("Enter new exam grade (0-40): ");
            scanf("%d", &newGrade);

            // Validate the new exam grade
            if (newGrade >= 0 && newGrade <= 40) {
                students[i].exam = newGrade;  // Update the exam grade
                calculateGrades(students, studentCount);  // Recalculate total grade and letter grade
                printf("Exam grade updated for student ID %d.\n", id);
            } else {
                printf("Invalid exam grade. Must be between 0 and 40.\n");
            }
            return;  // Exit the function after the update
        }
    }
    printf("Student ID not found.\n");  // If the student ID is not found
}
// Function to remove a student
void removeStudent() {
    int id;
    printf("Enter student ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].studentID == id) {
            // Shift all students after the removed one up by one
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student removed.\n");
            return;
        }
    }
    printf("Student ID not found.\n");
}
