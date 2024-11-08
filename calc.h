#ifndef CALC_H
#define CALC_H
#include "spreadsheet.h"

// Declare global grade thresholds with extern
extern int gradeA;
extern int gradeB;
extern int gradeC;
extern int gradeD;

// Function declarations related to calculations
void calculateGrades(Student students[], int studentCount);
void adjustGradeMapping();

#endif