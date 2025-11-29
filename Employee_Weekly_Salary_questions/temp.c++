#include<stdio.h>
#include<string.h>
int main() {
  int temp[5][7];
 int total;
float average=0;
char city[5][10000];
char highname[10000], lessname[10000];
int low=999999;
int high=-999999;
int i,j;

for(i=0; i<5; i++) {
printf("\n Enter  The city name %d:",i+1);
scanf("%s", city[i]);
 total=0;

for(j=0; j<7; j++){
printf("\n Enter the temperature for day %d:",j+1);
scanf("%d",&temp[i][j]);
total+=temp[i][j];
continue;
}
average= total/7.0;

printf("\n Total Temperature for %s :%d\n" ,city[i], total);
  printf("\n Average Temperature for %s:%.2f\n",city[i], average);

if(average> high) {
high=average;
strcpy(highname,name[i]);
}
if(average<low) {
low=average;
strcpy(lowname,name[i]);
}
}
 printf("\nCity with highest average temperature: %s (%.2f)\n", highname, high);
    printf("City with lowest average temperature: %s (%.2f)\n", lowname, low);

return 0;
}


