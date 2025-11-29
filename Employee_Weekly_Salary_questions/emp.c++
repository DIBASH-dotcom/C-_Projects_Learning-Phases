#include<stdio.h>
#include<string.h>

int main() {
  
    char name[5][1000];
    int salary[5][7];
    int total;
    int high = -99999;
    int low = 99999;
    char maxName[10000], minName[10000];
  int i,j;

    for(i = 0; i < 5; i++) {
        printf("\nEnter the employee name %d: ", i + 1);
        scanf("%s", name[i]);

        total = 0;

        for( j = 0; j < 7; j++) {
            printf("\nEnter the salary of day %d: ", j + 1);
            scanf("%d", &salary[i][j]);
            total += salary[i][j];
        }

        printf("\nWeekly salary of %s is %d\n", name[i], total);

        if(total < low) {
            low = total;
            strcpy(minName, name[i]);
        }

        if(total > high) {
            high = total;
            strcpy(maxName, name[i]);
        }
    }

    printf("\nThe least salary is earned by %s: Rs %d", minName, low);
    printf("\nThe highest salary is earned by %s: Rs %d\n", maxName, high);

    return 0;
}
