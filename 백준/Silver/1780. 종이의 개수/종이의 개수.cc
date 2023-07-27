#include <iostream>

using namespace std;

int n;
int minus_one=0;
int zero=0;
int plus_one=0;

int arr[2400][2400]; //3^7=2187

void dnc(int x, int y, int n) {
	bool flag =  true;
	for(int i=y;i<y+n;i++) {
		for(int j=x;j<x+n;j++) {
			if(arr[i][j] != arr[y][x]) {
				flag = false;
				break;
			}
		}
		if(!flag) break;
	}
	if(!flag) {
		dnc(x,y,n/3);				//1(0,0)
		dnc(x+n/3,y,n/3); 			//2(1,0)
		dnc(x+n/3*2,y,n/3); 		//3(2,0)
		dnc(x,y+n/3,n/3); 			//4(0,1)
		dnc(x+n/3,y+n/3,n/3); 		//5(1,1)
		dnc(x+n/3*2,y+n/3,n/3); 	//6(2,1)
		dnc(x,y+n/3*2,n/3); 		//7(0,2)
		dnc(x+n/3,y+n/3*2,n/3); 	//8(1,2)
		dnc(x+n/3*2,y+n/3*2,n/3); 	//9(2,2)
	}
	else {
		if(arr[y][x]==-1) minus_one++;
		else if(arr[y][x]==0) zero++;
		else plus_one++;
	}
}
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	
	cin >> n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin >> arr[i][j];
		}
	}

	dnc(0,0,n);

	cout << minus_one <<'\n' << zero << '\n' << plus_one;

	return 0;
}