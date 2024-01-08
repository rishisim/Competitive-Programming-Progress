// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);

	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> seeds(n);
	for(int i = 0; i < n; i++) {
		seeds[i] = -1;
	}

	for(int i = 0; i < n; i++) {
		seeds[i] = 1;
		for(int j = 0; j < graph[i].size(); j++) {
			if(i != j) {
				if(seeds[i] == seeds[graph[i][j]] && seeds[j] != -1) {
					seeds[i]+=1;
				}
			}
		}
		cout << seeds[i];
	}
}
