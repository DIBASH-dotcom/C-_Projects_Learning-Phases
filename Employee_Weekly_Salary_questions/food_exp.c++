#include<stdio.h>
#include<string.h>
int main() {
  
char name[5][1000];
int total;
int exp[5][7];
int high=-999999;
int low=999999;
char max[100000], min[10000000];
int i,j;

for(i=0; i<5; i++) {
printf("\n Enter the name of a studenst %d :",i+1);
scanf("%s", name[i]);

total=0;

for(j=0; j<7; j++) {
printf("\n Enter the expenses of a day %d:",j+1);
  scanf("%d",&exp[i][j]);
total+=exp[i][j];

}
printf("\n Weekly expenses of %s is %d \n", name[i] ,total);

if(total< low) {
low =total;
strcpy(min,name[i]);
}
if(total>high) {
high =total;
strcpy(max,name[i]);
}
}
printf("\n The less expense dobe by %s: Rs %d",min,low);
printf("\n tHE MORE EXPENses done by %s: Rs %d",max,high);
return 0;
}
