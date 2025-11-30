#include<stdio.h>
#include<string.h>
int main() {

int salary[5]={0};
char name[5][100];
int low=-99999;
int high=99999;
char max[1000], min[1000];
int i;

int sum=0;
 for(i=0; i<5; i++) {
printf("\n Enter the Employee name  of emplyoee %d:\n",i+1);
scanf("%s", name[i]);

printf("\n Enter The Salary of a empolyee %s: \n");
  scanf("%d",&salary[i]);

if(salary[i]<=0) {
printf("\n  Invalild error:\n");
  i--;
  continue;
  }
  
sum+=salary[i];

printf("\n The Salary of  %s is Rs %d: \n ",name[i],salary[i]);
if(salary[i]<low) {
low= salary[i];
strcpy(min,name[i]);
}
if(salary[i]>high) {
high= salary[i];
strcpy(max,name[i]);
}
}
printf("\n The largest salary emplyeess %s has got %d:", min,high);
printf("\n The smallest salary emplyess %s has got %d:",max,low);
return 0;
}
  
  
