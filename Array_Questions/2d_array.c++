#include<stdio.h>
#include<string.h>
int main() {
	int marks[3][4];
	char name[3][1000];
	int total[3]={0};
	float average=0;
	int i,j;
	char sub[3][4][1000];
	
	int maxmarks [4]={-1, -1, -1, -1};
	char tooper[4][100];
	
	for(i=0; i<3; i++) {
		printf("Enter the Name of students %d:",i+1);
		scanf("%s", name[i]);
		
		total[i]=0;
		
		for(j=0; j<4; j++) {
			printf("\n Enter the subjects name of  %s :", name[i]);
			scanf("%s", sub[i][j]);
			
			printf("\n Enter the Marks of %s :", sub[i][j]);
			scanf("%d", &marks[i][j]);
			
			while(marks[i][j]<0||marks[i][j]>100) {
				printf("Invaild marks \n");
				scanf("%d", &marks[i][j]);
				
			}
			
			total[i]+=marks[i][j];
			
		}
		printf("The Total marks of %s is %d \n ",name[i],total[i]);
		float avg= total[i]/4.0;
		printf("The average maeks of %s is %.2f\n \n", name[i],avg);
		
		
		}
		 for(j=0; j<4; j++) {
		 	for(i=0; i<3; i++) {
		 		if(marks[i][j] >maxmarks[j]) {
		 			maxmarks[j]= marks[i][j];
		 			strcpy(tooper[j], name[i]);
				 }
			 }
		 }
		
		
	
	 printf("\n--- Highest in Each Subject ---\n");
	 for(j=0; j<4; j++) {
	 	printf("%s:  %s %d \n",sub[j],tooper[j],maxmarks[j]);
	 }
	 return 0;
}
