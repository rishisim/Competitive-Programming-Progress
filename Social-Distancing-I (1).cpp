// // Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	freopen("socdist1.in", "r", stdin);
// 	// the following line creates/overwrites the output file
// 	freopen("socdist1.out", "w", stdout);

// 	int N; cin >> N;
// 	string s; cin >> s;

// 	int countOnes = 0;
// 	for(int i = 0; i < N; i++) {
// 		if(s[i] == '1') {countOnes++;}
// 	}
// 	if(countOnes == 0) {
// 		cout << N - 1;
// 		return 0;
// 	}

// 	vector<int> lens;
// 	int count = 0;
// 	for(int i = 0; i < N; i++) {
// 		if(s[i] == '1' && count > 0) {
// 			lens.push_back(count+1);
// 			count = 0;
// 		} else if(s[i] == '0') {
// 			count++;
// 		}
// 	}
// 	if(count > 0) {lens.push_back(count+1);}


// 	sort(begin(lens), end(lens));

// 	for(int i = 0; i < 2; i++) {
// 		int newAdd = lens[lens.size()-1]/2;
// 		if(lens[lens.size()-1]%2 != 0) {
// 			lens.push_back(newAdd+1);
// 		} else {
// 			lens.push_back(newAdd);
// 		}

// 		lens.push_back(newAdd);
// 		sort(begin(lens), end(lens));
// 		lens.erase(lens.end() - 1);
// 	}

// 	sort(begin(lens), end(lens));
// 	int ans1 = lens[0];

// 	cout << ans1;
// 	// AC for 1, 3, 4, 8, 11
// }

// // Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	freopen("socdist1.in", "r", stdin);
// 	// the following line creates/overwrites the output file
// 	freopen("socdist1.out", "w", stdout);

// 	int N; cin >> N;
// 	string s; cin >> s;

// 	int countOnes = 0;
// 	for(int i = 0; i < N; i++) {
// 		if(s[i] == '1') {countOnes++;}
// 	}
// 	if(countOnes == 0) {
// 		cout << N - 1;
// 		return 0;
// 	}

// 	vector<int> lens;
// 	int count = 0;
// 	for(int i = 0; i < N; i++) {
// 		if(s[i] == '1' && count > 0) {
// 			lens.push_back(count+1);
// 			count = 0;
// 		} else if(s[i] == '0') {
// 			count++;
// 		}
// 	}
// 	if(count > 0) {lens.push_back(count+1);}

// 	vector<int> lens2 = lens;
// 	// Algo 1;

// 	sort(begin(lens), end(lens));

// 	for(int i = 0; i < 2; i++) {
// 		int newAdd = lens[lens.size()-1]/2;
// 		if(lens[lens.size()-1]%2 != 0) {
// 			lens.push_back(newAdd+1);
// 		} else {
// 			lens.push_back(newAdd);
// 		}

// 		lens.push_back(newAdd);
// 		sort(begin(lens), end(lens));
// 		lens.erase(lens.end() - 1);
// 	}

// 	sort(begin(lens), end(lens));
// 	int ans1 = lens[0];

// 	//NEW CODE Algo 2;
// 	int ans2;
// 	sort(begin(lens2), end(lens2));
// 	int lensoverthree = lens2[lens2.size()-1]/3;
// 	if(lensoverthree >= 2) {
// 		if(lensoverthree < (lensoverthree + 0.5)) {
// 			ans2 = lensoverthree;
// 		} else {
// 			ans2 = lensoverthree+1;
// 		}
// 	} else {
// 		ans2 = INT_MIN;
// 	}

// 	cout << max(ans1, ans2);

// 	// AC for 1, 2, 3, 4, 8, 11
// }

#include <bits/stdc++.h>
using namespace std;

int find_largest_gap(string sf, int &gap_start) {
	int count = 0;
	int maxCount = 0;
	gap_start = 0;
	int size = sf.size();
	for(int i = 0; i < size; i++) {
		if(count > 0 && sf[i] == '1') {
			maxCount = max(count, maxCount);
			if(count == maxCount) {
				gap_start = i - maxCount + 1;
			}
			count = 0;
		} else if (sf[i] == '0') {
			count++;
		}
	}
	if(count > 0) {
		maxCount = max(count, maxCount);
		if(count == maxCount) {
			gap_start = size - maxCount ;
		}
	}

	return maxCount;
}

int find_smallest_gap(string sf) {
	int count = 0;
	int minCount = INT_MAX;
	int size = sf.size();
	for(int i = 0; i < size; i++) {
		if(count > 0 && sf[i] == '1') {
			minCount = min(count, minCount);
			count = 0;
		} else if (sf[i] == '0') {
			count++;
		}
	}
	if(count > 0) {
		minCount = min(count, minCount);
	}

	return minCount;
}

int put_in_largest_gap(string sf) {
	int gap_start;
	int largestGapf = find_largest_gap(sf, gap_start);

	if(largestGapf >= 2) {
		sf[gap_start + largestGapf/2] = '1';
		return find_smallest_gap(sf);
	}
	return -1;
}

int main() {
	// freopen("socdist1.in", "r", stdin);
	// // the following line creates/overwrites the output file
	// freopen("socdist1.out", "w", stdout);
	int N; cin >> N;
	string s; cin >> s; string temps;

	int gap_start;
	int largestGap = find_largest_gap(s, gap_start);

	int ans = 0;
	
	// Possibility 1: Both cows in largest gap.
	if(largestGap >= 2) {
		temps = s;
		temps[gap_start + largestGap/3] = '1';
		temps[gap_start + (2*largestGap)/3] = '1';
		ans = max(ans, find_smallest_gap(temps));
		cout << find_smallest_gap(temps) << " " << "1" << "\n";
	}

	// Possibility 2: Cow in Left and Cow Right.
	if(s[0] == '0' && s[N-1] == '0') {
		temps = s;
		temps[0] = '1'; temps[N-1] = '1';
		ans = max(ans, find_smallest_gap(temps));
		cout << find_smallest_gap(temps) << " " << "2" << "\n";
	}

	// Possibility 3: Cow in Largest + Cow in Second Largest
	if(largestGap >= 2) {
		temps = s;
		temps[gap_start + largestGap/2] = '1';
		ans = max(ans, put_in_largest_gap(temps));
		cout << put_in_largest_gap(temps) << " " << "3" << "\n";
	}

	// Possibility 4: Cow in Left + Cow in Largest
	if(s[0] == '0') {
		temps = s;
		temps[0] = '1';
		ans = max(ans, put_in_largest_gap(temps));
		cout << put_in_largest_gap(temps) << " " << "4" << "\n";
	}

	
	// Possibility 5: Cow in Right + Cow in Largest
	if(s[N-1] == '0') {
		temps = s;
		temps[N-1] = '1';
		ans = max(ans, put_in_largest_gap(temps));
		cout << put_in_largest_gap(temps) << " " << "5" << "\n";
	}

	cout << ans;
}
