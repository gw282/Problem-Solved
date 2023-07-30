/*
[2023-07-30 2447 별찍기-10]
귀납적으로 생각, 분할정복하기
패턴에서 (1,1)인 경우에만 공백 출력
n*n이 3*3보다 작아진 경우 * 출력
*/
#include <iostream>

using namespace std;

void star(int i, int j, int n) {
	if((i/n)%3==1 && (j/n)%3==1) printf(" "); // 공백인 칸인 경우
	else {
		if(n/3==0) printf("*"); // n이 패턴 크기보다 작아진 경우
		else star(i,j,n/3);
	}
}
int main(void) { 
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    	
	int i, j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			star(i,j,n);
		}
		printf("\n");
	}
    
}