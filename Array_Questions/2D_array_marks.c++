#include <stdio.h>

int main() {
    int marks[3][4];           
    char sub[3][4][100];       
    char name[3][100];         
    int i, j;

    for(i = 0; i < 3; i++) {
        printf("\nEnter the name of student %d: ", i + 1);
        scanf("%s", name[i]);

        int sum = 0;  

        for(j = 0; j < 4; j++) {
            printf("Enter subject %d name: ", j + 1);
            scanf("%s", sub[i][j]);

            printf("Enter marks for %s: ", sub[i][j]);
            scanf("%d", &marks[i][j]);

            while(marks[i][j] < 0 || marks[i][j] > 100) {
                printf("Invalid marks! Enter again (0-100): ");
                scanf("%d", &marks[i][j]);
            }

            sum += marks[i][j];
        }

        printf("\nTotal marks of %s: %d", name[i], sum);
        printf("\nAverage marks of %s: %.2f\n", name[i], sum / 4.0);
    }

    return 0;
}
