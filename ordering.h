// ordering.h
#ifndef  ORDERING_H
#define ORDERING_H
#include "spreadsheet.h"

//Sorting function declarations 
void sortByID(Student students[], int studentCount);
void sortByLastName(Student students[], int studentCount);
void sortByExamGrade(Student students[], int studentCount);
void sortByTotalGrade(Student students[], int studentCount);
void sortMenu();
// Comparison function declarations
int compareByID(const void *a, const void *b);
int compareByLastName(const void *a, const void *b);
int compareByExamGrade(const void *a, const void *b);
int compareByTotalGrade(const void *a, const void *b);

#endif