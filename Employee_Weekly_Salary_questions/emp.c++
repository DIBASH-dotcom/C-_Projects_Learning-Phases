#include<stdio.h>
#include<conio.h>
int main() {
  int emp[5][7];
char name[5] [1000];
int total=0;
int salary[5][7];
int high=-99999;
int low=99999;
int i;
int j;
char max[10000] min[10000];

for(i=0; i<5; i++) {
printf(" /n Enter the employee name %d :",i+1);
scanf("%s" , name[i]);

for(j=0; j<7; j++) {
printf(" /n Enter the salary of a day%d:",j+1);
scanf("%d", &salary[i][j]);
total=+ salary[i][j];
continue;
}


if(total<low) {
low =total;
strcpy(low,name[i]);
}

if(total>high) {
high= total;
strcpy(high,name[i]);
}
}
printf(" /n The wekkly salry of %s is  %d:",name[i],total);
printf(" /n The less salry got by %s which is Rs%d:",name[i] min);
printf("/n The more salary got by %s which is Rs%d:",name[i] max);
 return 0;
}


  
