/*
Javan Ichingwa
PA106/G/28767/25
2D array scores
*/

#include<stdio.h>

int main (){
	int i ,j;
	
	
	int scores[2][2]={
	{65, 70},
	{84, 67},
};
// using nested for loop to print the elements
printf("Elements of the scores array:\n");
for(i=0; i<2; i++){
	for(j=0; j<2; j++){
		printf("%d\t",scores[i][j]);
	}
	printf("\n");
	
}
	
	
	
	
	
	return 0;
}