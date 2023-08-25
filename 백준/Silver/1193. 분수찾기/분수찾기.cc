#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	/*
	1/1 홀 
	1/2 2/1 짝 
	3/1 2/2 1/3 홀 
	1/4 2/3 3/2 4/1 
	5/1 4/2 3/3 2/4 1/5
	1/6 2/5 3/4 4/3 5/2 6/1
	*/
	
	int x;
	int n,i;
	int s,m;
	scanf("%d",&x);
	
	for(int i=1;;i++) {
		if(i*(i+1)/2>=x) {
			n=i;
			break;
		}
	}
	
	int num=x-((n-1)*n/2); //(n-1)(n+1-1)/2
	
	if(n%2==0) {
		m=n,s=1;
		for(i=0;i<num-1;i++){ 
			m--,s++;
		}
	}
	else {
		m=1,s=n;
		for(i=0;i<num-1;i++){
			m++,s--;
		}
	}
	printf("%d/%d",s,m);
	
	return 0;
}
