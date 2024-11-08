# C-Spreadsheet-App
Grade Management Spreadsheet in C
Overview

This project is a streamlined spreadsheet application written in C, designed to manage and calculate student grades. It mimics some basic functionalities of a traditional spreadsheet, making it ideal for handling student records in a structured format. The application reads data from a text file, processes it, and provides a menu-driven interface to display, manipulate, and analyze student grades.

Features

	1.	Display Spreadsheet: Shows all student data in a neatly formatted table with dynamic calculations for total scores and letter grades.
	2.	Grade Distribution Histogram: Graphically represents the distribution of grades across the class.
	3.	Sorting Options: Allows sorting based on student ID, last name, exam grade, or total grade.
	4.	Data Modification:
		•	Update last names or exam grades for specific students.
	5.	Adjustable Grade Mapping: Configure custom grade boundaries to adjust letter grades.
	6.	Student Removal: Remove students from the dataset easily.

How It Works

The application reads a students.txt file where each line contains:
```
 <Student ID>|<Last Name>|<First Name>|<Assignment 1>|<Assignment 2>|<Assignment 3>|<Midterm>|<Exam>
```
Grades are parsed, weighted, and displayed with letter grades based on configurable thresholds.
Menu Options

The application offers an intuitive menu with the following options:
	1.	Display Spreadsheet - View student data with calculated totals and letter grades.
	2.	View Grade Distribution - Check a histogram of grades (A, B, C, D, F).
	3.	Sort Data - Sort student records by various criteria.
	4.	Update Last Name - Modify the last name of a specific student.
	5.	Update Exam Grade - Change the exam grade of a student.
	6.	Adjust Grade Mappings - Customize the boundaries for letter grades.
	7.	Remove a Student - Permanently delete a student record from the list.
	8.	Exit - Close the application with a friendly goodbye message.
 Code Structure

	•	spreadsheet.c: Handles the main menu and GUI elements.
	•	data.c: Manages data input and processing.
	•	ordering.c: Provides sorting functionality for student records.
	•	calc.c: Executes various calculations for grades and totals.

Future Improvements

Potential extensions to enhance functionality:
	•	Support for error handling in data entries.
	•	Enhanced UI elements for improved user experience.
	•	Additional statistical analysis for student performance.
