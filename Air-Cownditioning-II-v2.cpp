// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#include <numeric>

bool sortbyfourth(const tuple<int, int, int, int>& a,  
              const tuple<int, int, int, int>& b) 
{ 
    return (get<3>(a) < get<3>(b)); 
} 

int main() {
	int cowCount, conditionerCount;
	cin >> cowCount >> conditionerCount;

	vector<tuple<int, int, int>> cowInfo(cowCount);

	int statesSize = INT_MIN;

	for(int i = 0; i < cowCount; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		statesSize = max(statesSize, b);

		cowInfo[i] = tie(a, b, c);
	}

	vector<tuple<int, int, int, int>> condInfo(conditionerCount);

	for(int i = 0; i < conditionerCount; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		condInfo[i] = tie(a, b, c, d);
	}

	vector<int> states(statesSize);
	for(int i = 0; i < cowCount; i++) {
		int si = get<0>(cowInfo[i]) - 1;
		int ti = get<1>(cowInfo[i]);
		for(int j = si; j < ti; j++) {
			states[j] = get<2>(cowInfo[i]);
		}
	}

	sort(condInfo.begin(), condInfo.end());
	vector<int> costV;

	while(next_permutation(condInfo.begin(), condInfo.end())) {
		vector<int> statescopy = states;
		int cost = 0;
		for(int i = 0; i < conditionerCount; i++) {
			int ai = get<0>(condInfo[i]) - 1;
			int bi = get<1>(condInfo[i]);
			int pi = get<2>(condInfo[i]);
			int mi = get<3>(condInfo[i]);
			for(int x = ai; x < bi; x++) {
				statescopy[x] -= pi;
				if(statescopy[x] < 0) {
					statescopy[x] = 0;
				}
			}

			cost += mi;
			if(accumulate(statescopy.begin(), statescopy.end(), 0) <= 0) {
				break;
			}
		}

		costV.push_back(cost);
	}

	sort(costV.begin(), costV.end());

	cout << costV[0];
}
