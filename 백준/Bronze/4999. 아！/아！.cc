#include <iostream>
#include <string>

using namespace std;

int main() {
	string able; // 재환이가 낼 수 있는 aaah
	string want; // 의사가 원하는 aah;

	getline(cin, able, '\n');
	getline(cin, want, '\n');

	if (able.size() >= want.size()) cout << "go";
	else cout << "no";

}