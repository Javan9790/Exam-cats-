/*
Javan Ichingwa
PA106/G/28767/25
program to calculate net pay
*/

#include <stdio.h>

int main(){
	float hours,wage,gross_pay,taxes,net_pay;
	
	printf("Enter hours worked in a week:");
	scanf("%f", &hours);
	
	printf("Enter hourly wage:");
	scanf("%f", &wage);
	printf("\n");
	
	//gross pay
	if(hours<=40){
		gross_pay=hours*wage;
	}
	else{
		gross_pay=40*wage +(hours-40)*wage*1.5;
	}
	
	//tax
	if(gross_pay<=600){
		taxes=gross_pay*0.15;
	}
	else{
		taxes=600*0.15+(gross_pay-600)*0.20;
	}
	
	//net pay
	net_pay=gross_pay-taxes;
	
	//output
	printf("Gross pay:%.2f\n", gross_pay);
	printf("Taxes:%.2f\n", taxes);
	printf("Net pay:%.2f\n", net_pay);
	
	return 0;
}