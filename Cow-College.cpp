// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	vector<ll> tuition(n);
	for(ll i = 0; i < n; i++) {
		cin >> tuition[i];
	}

	vector<ll> tuitionFiltered = tuition;
	sort(tuitionFiltered.begin(), tuitionFiltered.end());
	auto last = unique(tuitionFiltered.begin(), tuitionFiltered.end());
	tuitionFiltered.erase(last, tuitionFiltered.end());

	// for(ll i = 0; i < tuitionFiltered.size(); i++) {
	// 	cout << tuitionFiltered[i];
	// }

	// int maxPrice = INT_MIN;
	// int minCount = INT_MAX;

	
	int maxPrice;
	int minCount;

	for(ll i = tuitionFiltered.size() - 1; i >= 0; i--) {
		int price = tuitionFiltered[i];
		int count = 0;
		for(int j = 0; j < n; j++)  {
			if(tuition[j] >= tuitionFiltered[i]) {
				count++;
			}
		}
		
		if(i == tuitionFiltered.size() - 1) {
			maxPrice = price;
			minCount = count;
		} else {
			if(maxPrice * minCount <= price * count) {
				if(price <= maxPrice) {
					maxPrice = price;
					minCount = count;
				}
			}
		}
	}

	cout << maxPrice * minCount << " " << maxPrice;
}
