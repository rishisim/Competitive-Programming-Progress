// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> cowsList(n);
	for(int i = 0; i < n; i++) {
		cin >> cowsList[i];
	}

	vector<vector<int>> cows(n, vector<int> (n));

	// for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < n; j++) {
	// 		cin >> cows[i][j];
	// 	}
	// }

	for(int i = 0; i < n; i++) {
		int j = cowsList[i];
		while (j) {
			cows[i].push_back(j % 10);
			j /= 10;
		}
		reverse(cows[i].begin(), cows[i].end());
	}


	// for(int i = 0; i < n; i++) {
	// 	int num = cowsList[i];
	// 	for(int j = 0; j < n; j++) {
	// 		cows[i][j] = num[j];
	// 	}
	// }

	// for(int i = 0; i < n; i++) {
	// 	ostringstream os; os << number; 
	// 	string digits = os.str();
	// 	for(int j = 0; j < n; j++) {
	// 		cows[i][j] = num[j];
	// 	}
	// }


	int count = 0;

	for(int i = n-1; i >= 0; i--) {
		for(int j = n-1; j >= 0; j--) {
			if(cows[i][j] == 1) {
				for(int x = 0; x <= i; x++) {
					for(int h = 0; h <= j; h++) {
						if(cows[x][h] == 0) {
							cows[x][h] = 1;
						} else {
							cows[x][h] = 0;
						}
					}
				}
				count++;
			}
		}
	}

	cout << count;
}
