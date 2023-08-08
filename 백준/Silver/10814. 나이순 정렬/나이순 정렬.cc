#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Member {
	string name;
	int age;
};

bool cmp(const Member a, Member b) {
	return a.age < b.age;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
	cin >> n;

	vector <Member> v(n);
	for(int i=0;i<n;i++) {
		cin >> v[i].age >> v[i].name;
	}

	stable_sort(v.begin(),v.end(), cmp);

	for(int i=0;i<n;i++) {
		cout << v[i].age << " " << v[i].name << '\n';
	}
	return 0;
}