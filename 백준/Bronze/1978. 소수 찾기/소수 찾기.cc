#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	
	int num;
	int n,i;
	int cnt=0;
	
	scanf("%d",&num);
	
	while(num--) {
		scanf("%d",&n);
		
		for(i=2;i<n;i++) {
			if(n%i==0) break;
		}
		if(i==n) cnt++;
	}
	
	printf("%d",cnt);
	
	return 0;
}