#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ITEMS 10

// Function to calculate grade based on average marks
char calculate_grade(int avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}

int main() {
    char names[NUM_ITEMS][50];
    int subj1[NUM_ITEMS], subj2[NUM_ITEMS], subj3[NUM_ITEMS];
    char grades[NUM_ITEMS];
    
    // Input data
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        getchar(); // To consume the leftover newline character
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = 0; // Remove newline character
        printf("Subject 1 marks: ");
        scanf("%d", &subj1[i]);
        printf("Subject 2 marks: ");
        scanf("%d", &subj2[i]);
        printf("Subject 3 marks: ");
        scanf("%d", &subj3[i]);
        
        // Calculate grade
        int avg = (subj1[i] + subj2[i] + subj3[i]) / 3;
        grades[i] = calculate_grade(avg);
        printf("\n");
    }
    
    // Display data
    printf("\nStudent Records:\n");
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Name", "Subj1", "Subj2", "Subj3", "Grade");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("%-20s %-10d %-10d %-10d %-10c\n", names[i], subj1[i], subj2[i], subj3[i], grades[i]);
    }
    
    return 0;
}

