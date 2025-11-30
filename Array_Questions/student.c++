#include<stdio.h>
#include <string.h>
int main() {
  int marks[5];
char name[5][100];
int i;
char maxname[100] ,minname[100];
int high=-99999,low=999999;
  int sum=0;

for(i=0; i<5; i++) {
printf(" \n Enter the name of a students %d:",i+1);
scanf("%s", name[i]);

printf("\n Enter the marks of students %d:",i+1);
scanf("%d",&marks[i]);

if(marks[i]<0||marks[i]>100) {
printf("Invaild Marks");
  i--;
continue;
}

sum=marks[i];

if(marks[i]<low) {
low= marks[i];
  strcpy(name[i],minname);
}

if(marks[i]>high) {
high= marks[i];
strcpy(name[i],maxname);
  }
}

printf("\n The marks of a students is %d:",marks[i]);
printf("\n The lowerst marks of a student is %d secured by %s :",low,minname[i]);
printf("\n the largest marks of a student is %d secured by %s:",high,maxname[i]);
return 0;
}

