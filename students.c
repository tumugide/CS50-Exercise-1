#include <stdio.h>

#define NUM_ITEMS 5

// Define a structure to hold the data
typedef struct {
    char name[50];
    int subj1, subj2, subj3;
    char grade;
} Student;

// Function to calculate grade based on average marks
char calculate_grade(int avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

int main() {
    Student students[NUM_ITEMS];
    
    // Input data
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        getchar(); // To consume the leftover newline character
        fgets(students[i].name, sizeof(students[i].name), stdin);
        printf("Subject 1 marks: ");
        scanf("%d", &students[i].subj1);
        printf("Subject 2 marks: ");
        scanf("%d", &students[i].subj2);
        printf("Subject 3 marks: ");
        scanf("%d", &students[i].subj3);
        
        // Calculate grade
        int avg = (students[i].subj1 + students[i].subj2 + students[i].subj3) / 3;
        students[i].grade = calculate_grade(avg);
        printf("\n");
    }
    
    // Display data
    printf("\nStudent Records:\n");
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Name", "Subj1", "Subj2", "Subj3", "Grade");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%-20s %-10d %-10d %-10d %-10c\n", students[i].name, students[i].subj1, students[i].subj2, students[i].subj3, students[i].grade);
    }
    
    return 0;
}
