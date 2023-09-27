#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READONLY "r"
#define WRITEONLY "w"
#define MAX_STUDENTS 99

typedef struct student {
    char firstName[20];
    char lastName[20];
    int grade;
} Student;

void bubbleSort(Student[], int);
int countLinesInFile(FILE *);
void writeStructToFile(Student[], int);

int main() {
    char fileName[20];
    printf("Enter name of file containing student records to be sorted: ");
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, READONLY);
    if (!fp) {
        printf("Failed to open file %s.\n", fileName);
        exit(1);
    }

    Student st[MAX_STUDENTS];
    for (int i = 0; i < MAX_STUDENTS; i++) {
        fscanf(fp, "%s %s %d", st[i].lastName, st[i].firstName, &st[i].grade);
    }

    int count = countLinesInFile(fp);
    bubbleSort(st, count);
    writeStructToFile(st, count);
    
    fclose(fp);

    printf("Program has been successful!\n");
    return 0;
}

int countLinesInFile(FILE *fp) {
    rewind(fp);
    int count = 0;
    char c;

    while ((c = getc(fp)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }

    return count;
}

void bubbleSort(Student st[], int count) {
    int k = 1;
    int exchange_made = 1;
    
    while ((k < count) && exchange_made) {
        exchange_made = 0;
        for (int j = 0; j < count - k; j++) {
            if (strcmp(st[j].lastName, st[j + 1].lastName) > 0) {
                Student temp = st[j];
                st[j] = st[j+1];
                st[j+1] = temp;
                exchange_made = 1;
            }
        }
        k++;
    }
}

void writeStructToFile(Student st[], int count) {
    FILE *outFile = fopen("sorted.txt", WRITEONLY);
    if (!outFile) {
        printf("\nFailed to open sorted.txt for writing.");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(outFile, "%s %s %d\n", st[i].lastName, st[i].firstName, st[i].grade);
    }

    fclose(outFile);
}
