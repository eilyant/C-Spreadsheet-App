#include "calc.h"
#include "spreadsheet.h"
#include <stdio.h>



extern int gradeA;
extern int gradeB;
extern int gradeC;
extern int gradeD;
extern int studentCount;
extern Student *students;
// Function to calculate total grades and assign letter grades

void calculateGrades(Student students[], int studentCount) {
    for (int i = 0; i < studentCount; i++) {
        // Calculate final grade based on weighted contributions
        double assignmentTotal = (students[i].A1 + students[i].A2 + students[i].A3) / 120.0 * 25.0;
        double midtermTotal = students[i].midterm / 25.0 * 25.0;
        double examTotal = students[i].exam / 40.0 * 50.0;

        // Calculate the final total grade
        students[i].totalGrade = assignmentTotal + midtermTotal + examTotal;

        // Assign letter grades based on the new grade thresholds
        if (students[i].totalGrade >= gradeA)
            students[i].letterGrade = 'A';
        else if (students[i].totalGrade >= gradeB)
            students[i].letterGrade = 'B';
        else if (students[i].totalGrade >= gradeC)
            students[i].letterGrade = 'C';
        else if (students[i].totalGrade >= gradeD)
            students[i].letterGrade = 'D';
        else
            students[i].letterGrade = 'F';
    }
}
// Function to adjust grade mappings with input validation
void adjustGradeMapping() {
    int tempA, tempB, tempC, tempD;

    // Display the current mapping
    printf("Current Mapping:\n");
    printf("  A: >= %d\n", gradeA);
    printf("  B: >= %d\n", gradeB);
    printf("  C: >= %d\n", gradeC);
    printf("  D: >= %d\n", gradeD);
    printf("  F: < %d\n", gradeD);

    // Input validation loop for new grade thresholds
    while (1) {
        // Prompt the user for new baseline values
        printf("\nEnter new A baseline (0-100): ");
        scanf("%d", &tempA);

        printf("Enter new B baseline (0-100): ");
        scanf("%d", &tempB);

        printf("Enter new C baseline (0-100): ");
        scanf("%d", &tempC);

        printf("Enter new D baseline (0-100): ");
        scanf("%d", &tempD);

        // Check that all values are between 0 and 100 and are in descending order
        if (tempA >= tempB && tempB >= tempC && tempC >= tempD && tempA <= 100 && tempD >= 0) {
            // Valid input: update the grade mappings
            gradeA = tempA;
            gradeB = tempB;
            gradeC = tempC;
            gradeD = tempD;
            break;  // Exit the loop once valid input is provided
        } else {
            // Invalid input: display an error message and prompt again
            printf("Error: Grades must be between 0 and 100 and in descending order (A >= B >= C >= D >= 0). Please try again.\n");
        }
    }

    // Display the new mapping
    printf("\nNew Mapping:\n");
    printf("  A: >= %d\n", gradeA);
    printf("  B: >= %d\n", gradeB);
    printf("  C: >= %d\n", gradeC);
    printf("  D: >= %d\n", gradeD);
    printf("  F: < %d\n", gradeD);

    // Recalculate grades based on new mappings
    calculateGrades(students, studentCount);

    
}