#include<stdio.h>
#include<string.h>
int main() {
	char name[5][100];
	int price[5]={0};
	int high=-99999;
	int low=9999;
	int i;
	int sum=0;
	char max[1000],min[1000];
	
	for(i=0; i<5; i++) {
		printf("\n Enter the products name %d:",i+1);
		scanf("%s", name[i]);
		
		printf("\n Enter the price of a %s :",name[i]);
		scanf("%d",&price[i]);
		
		if(price[i]<=0) {
			printf("\n Invaild please price");
			i--;
			continue;
		}
		sum += price[i];
		printf("\n The Price of a %s is Rs %d:\n",name[i],price[i]);
		
		if(price[i]<low) {
			low=price[i];
			strcpy(min,name[i]);
		}
		
		if(price[i]>high) {
			high=price[i];
			strcpy(max,name[i]);
		}
		
		
	}
	printf("\n The highest  products name is %s : price is Rs%d",max,high);
	printf("\n The Lowest Products name is %s : price is  Rs %d",min,low);
	return 0;

	
	
	}
