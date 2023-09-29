# STUDENT SORTER
Using the BubbleSort Algorithm

---

## 1. Description

This program reads a file containing student records, sorts the records based on the student's last name using the BubbleSort algorithm, and writes the sorted list to "sorted.txt".

## 2. How to Compile & Run

$ gcc -o sorter sorter.c
$ ./sorter

## 3. Usage
Upon execution, the program prompts for the name of the file containing student records.
Each line of the file should have the format: LastName FirstName Grade, e.g., Doe John 85.
The program will sort based on the last name and write the sorted list to sorted.txt.

## 4. Files
sorter.c: The main source code for the student record sorter.

## 5. Functions
countLinesInFile: Counts the number of lines in a given file.
bubbleSort: Sorts an array of student structures based on the last name using the BubbleSort algorithm.
writeStructToFile: Writes an array of student structures to sorted.txt.

## 6. Data Structures
Student: A structure representing a student, containing first name, last name, and grade.

## 7. Notes
Ensure the input file exists and is accessible to avoid errors.
The input file should not exceed 99 student records.
The program outputs to a file named sorted.txt.
Sorting is based on ASCII values, so it's case-sensitive.
