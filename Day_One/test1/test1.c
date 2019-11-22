#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void main01(){
	int i = 0,j = 0,tmp = 0;
	int a[] = {33,44,55,32,1,67,9};
	for (i=0;i<7;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
	
	//sort
	for (i=0;i<7;i++){
		for (j=i+1;j<7;j++){
			if (a[i] > a[j]){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		
	}
	for (i=0;i<7;i++){
		printf("%d\t",a[i]);
	}

	printf("\n Hello world! \n");
	return ;
}

void printfArray(int a[7]){
	int  i = 0;
	for (i=0;i<7;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void sortArray(int a[7]){
	int i=0,j=0,tmp=0;
	for (i=0;i<7;i++){
		for (j=i+1;j<7;j++){
			if (a[i] > a[j]){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		
	}
}

void printfArray1(int a[],int len){
	int  i = 0;
	for (i=0;i<len;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void sortArray1(int a[],int len){
	int i=0,j=0,tmp=0;
	for (i=0;i<len;i++){
		for (j=i+1;j<len;j++){
			if (a[i] > a[j]){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		
	}
}

void printfArray2(int *a,int len){
	int  i = 0;
	for (i=0;i<len;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void sortArray2(int *a,int len){
	int i=0,j=0,tmp=0;
	
	int Len2 =0;
	Len2 = sizeof(a)/sizeof(a[0]);
	printf("%d \n",Len2);

	for (i=0;i<len;i++){
		for (j=i+1;j<len;j++){
			if (a[i] > a[j]){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		
	}
}


void main(){
	int arrayLen = 0;
	int a[] = {33,44,55,32,1,67,9,666};
	arrayLen = sizeof(a)/sizeof(a[0]);	
/*	printfArray(a);
	//sort
	sortArray(a);
	printfArray(a);
*
	printfArray1(a,arrayLen);
	//sort
	sortArray1(a,arrayLen);
	printfArray1(a,arrayLen);
*/
	printfArray2(a,arrayLen);
	//sort
	sortArray2(a,arrayLen);
	printfArray2(a,arrayLen);

	printf("\n Hello world! \n");
	return ;
}
