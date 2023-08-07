#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	
	int num,tmp;
	int arr[1000];
	scanf("%d",&num);
	
	for(int i=0;i<num;i++) {
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<num-1;i++) {
		for(int j=i+1;j<num;j++) {
			if(arr[i]>arr[j]) {
				tmp= arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;
			}
		}
	}
	
	for(int i=0;i<num;i++) {
		printf("%d\n",arr[i]);
	}
	
	return 0;
}