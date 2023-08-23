#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1000001];

int main(void) {
	int m,n;
	
	arr[1000001]={0,};
	arr[0]=1;
	arr[1]=1;
	
	scanf("%d %d",&m,&n);
	
	for(int i=2;i<=n;i++) {
		if(!arr[i]) {
			for(int j=i+i;j<=n;j+=i)
				arr[j]=1;
		}
		if(i>=m&&arr[i]==0) printf("%d\n",i);
	}
	return 0;
}