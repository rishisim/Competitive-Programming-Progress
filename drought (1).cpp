// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n; cin >> n;
	vector<ll> h(n+1);
	for(int i = 1; i <= n; i++) cin >> h[i];

	ll bags = 0;

	for(int i = 1; i < n; i++) {
		if(h[i+1] > h[i]) {
			if(i+2 > n) {
				cout << "-1\n";
				return;
			}

			ll difference = h[i+1] - h[i];
			h[i+1] -= difference;
			h[i+2] -= difference;

			if(h[i+2] < 0) {
				cout << "-1\n";
				return;
			}

			bags += difference*2;
		} else if (h[i] > h[i+1]) {
			if(i%2 == 1) {
				cout << "-1\n";
				return;
			}

			ll difference = h[i] - h[i+1];
			bags += i*difference;
		}
	}

	cout << bags << "\n";
}

int main() {
	int tests;
	cin >> tests;
	for(int i = 0; i < tests; i++) solve();
}
