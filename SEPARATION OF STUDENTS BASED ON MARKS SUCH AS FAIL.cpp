#include <stdio.h>
#include <string.h>

// Define a structure for student data
struct Student {
    int rollNo;
    char name[50];
    float marks;
    char section[10];  // Section added
};

void enterStudentData(struct Student students[], int totalStudents);
void displayStudentData(struct Student students[], int totalStudents);
void displayLowMarksStudents(struct Student students[], int totalStudents);
void displaySectionStudents(struct Student students[], int totalStudents, const char* section);

int main() {
    int totalStudents;

    // Asking for number of students in the class
    printf("Enter the number of students in the class: ");
    scanf("%d", &totalStudents);

    // Declare an array of structures to store student data
    struct Student students[totalStudents];

    // Call the function to enter student data
    enterStudentData(students, totalStudents);

    // Displaying all the entered student data
    printf("\nStudent Data Entered:\n");
    displayStudentData(students, totalStudents);

    // Display students with marks less than 29
    displayLowMarksStudents(students, totalStudents);

    // Display students in different sections
    printf("\nDisplaying students by Section:\n");
    displaySectionStudents(students, totalStudents, "A");
    displaySectionStudents(students, totalStudents, "B");

    return 0;
}

// Function to input student data
void enterStudentData(struct Student students[], int totalStudents) {
    for (int i = 0; i < totalStudents; i++) {
        printf("\nEnter details for Student %d\n", i + 1);
        
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNo);
        
        printf("Enter Name: ");
        getchar();  // To consume the leftover newline character
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // Remove newline character
        
        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);

        printf("Enter Section: ");
        getchar();  // To consume any leftover newline character from previous input
        fgets(students[i].section, 10, stdin);
        students[i].section[strcspn(students[i].section, "\n")] = 0; // Remove newline character
    }
}

// Function to display all student data in a table format
void displayStudentData(struct Student students[], int totalStudents) {
    // Print the table header
    printf("\n%-10s%-30s%-10s%-10s\n", "Roll No", "Name", "Marks", "Section");
    printf("---------------------------------------------------------------\n");
    
    // Print each student's data in a tabular format
    for (int i = 0; i < totalStudents; i++) {
        printf("%-10d%-30s%-10.2f%-10s\n", students[i].rollNo, students[i].name, students[i].marks, students[i].section);
    }
}

// Function to display students with marks less than 29
void displayLowMarksStudents(struct Student students[], int totalStudents) {
    printf("\nStudents with Marks Less Than 29:\n");
    printf("%-10s%-30s%-10s%-10s\n", "Roll No", "Name", "Marks", "Section");
    printf("---------------------------------------------------------------\n");
    
    int found = 0;
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].marks < 29) {
            printf("%-10d%-30s%-10.2f%-10s\n", students[i].rollNo, students[i].name, students[i].marks, students[i].section);
            found = 1;
        }
    }

    if (!found) {
        printf("No students found with marks less than 29.\n");
    }
}

// Function to display students in a specific section
void displaySectionStudents(struct Student students[], int totalStudents, const char* section) {
    int found = 0;
    printf("\nStudents in Section %s:\n", section);
    printf("%-10s%-30s%-10s%-10s\n", "Roll No", "Name", "Marks", "Section");
    printf("---------------------------------------------------------------\n");
    
    for (int i = 0; i < totalStudents; i++) {
        if (strcmp(students[i].section, section) == 0) {
            printf("%-10d%-30s%-10.2f%-10s\n", students[i].rollNo, students[i].name, students[i].marks, students[i].section);
            found = 1;
        }
    }

    if (!found) {
        printf("No students found in Section %s.\n", section);
    }
}

