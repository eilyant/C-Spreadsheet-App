#ifndef SPREADSHEET_H
#define SPREADSHEET_H

// Maximum number of students
#define MAX_STUDENTS 100

// Structure for Student
typedef struct {
    int studentID;
    char lastName[50];
    char firstName[50];
    int A1, A2, A3, midterm, exam;
    double totalGrade;
    char letterGrade;
} Student;

// Function declarations related to menu and basic GUI
void displayMenu();
void displaySpreadsheet();
void showHistogram();  
#endif