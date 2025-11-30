#include <stdio.h>
#include <string.h>

int main() {
    int marks[3][4];
    char subjects[4][20] = {"Math", "Science", "English", "Nepali"};
    char name[3][100];

    for(int i = 0; i < 3; i++) {
        printf("\nEnter student %d name: ", i+1);
        scanf("%s", name[i]);

        int sum = 0;

        for(int j = 0; j < 4; j++) {
            printf("Enter marks for %s: ", subjects[j]);
            scanf("%d", &marks[i][j]);

            while(marks[i][j] < 0 || marks[i][j] > 100) {
                printf("Invalid! Enter marks (0-100): ");
                scanf("%d", &marks[i][j]);
            }

            sum += marks[i][j];
        }

        float avg = sum / 4.0;

        printf("\nTotal marks of %s = %d", name[i], sum);
        printf("\nAverage marks of %s = %.2f\n", name[i], avg);
    }

    return 0;
}
