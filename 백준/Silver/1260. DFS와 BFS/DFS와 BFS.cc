#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#define MAX 1001

using namespace std;

bool vis[MAX];
vector <int> adj[MAX];
queue <int> q;
stack <int> s;

bool desc(int a,int b) {
	return a>b;
}

void bfs(int cur) {
	q.push(cur);
	vis[cur] = true;
	while(!q.empty()) {	
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for(int i=0;i<adj[cur].size();i++) {
			if(vis[adj[cur][i]]) continue;
			q.push(adj[cur][i]);
			vis[adj[cur][i]]=true;
		}
	}
}

void dfs(int cur) {
	s.push(cur);
	while(!s.empty()) {	
		int cur = s.top();
		s.pop();
		if(vis[cur]) continue;
		vis[cur] = true;
		cout << cur << ' ';
		for(int i=0;i<adj[cur].size();i++) {
			int nxt = adj[cur][adj[cur].size()-1-i];
			if(vis[nxt]) continue;
			s.push(nxt);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	
	int n,m,v;
	cin >> n >> m >> v;

	for(int i=0;i<m;i++) {
		int a,b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i=1;i<=n;i++) {
		sort(adj[i].begin(),adj[i].end());
	}
	
	dfs(v);
	memset(vis,false,sizeof(vis));
	cout << '\n';
	bfs(v);

	return 0;
}