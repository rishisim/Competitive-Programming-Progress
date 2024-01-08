// // Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int n;
// 	cin >> n;

// 	vector<char> cowsType(n);
// 	vector<int> cowsList(n);

// 	for(int i = 0; i < n; i++) {
// 		cin >> cowsType[i];
// 	}

// 	for(int i = 0; i < n; i++) {
// 		cin >> cowsList[i];
// 	}

// 	int HCount = 0, GCount = 0;

// 	for(int i = 0; i < n; i++) {
// 		if (cowsType[i] == 'H') {
// 			HCount++;
// 		} else {
// 			GCount++;
// 		}
// 	}

// 	int lHcount = 0, lGcount = 0;

// 	for(int i = 0; i < n; i++) {
// 		int count = 0;
// 		for(int j = i; j < cowsList[i]; j++) {
// 			if(cowsType[i] == 'G') {
// 				if(cowsType[j] == 'G') {
// 					count++;
// 				}

// 				if(cowsType[j] == 'H') {
// 					lGcount++;
// 					break;
// 				}
				
// 				if(count == GCount) {
// 					lGcount++;
// 					break;
// 				}
// 			} else {
// 				if(cowsType[i] == 'H') {
// 					if(cowsType[j] == 'H') {
// 						count++;
// 					}

// 					if(cowsType[j] == 'G') {
// 						lHcount++;
// 						break;
// 					}
// 				}

// 				if(count == HCount) {
// 					lHcount++;
// 					break;
// 				}
// 			}
// 		}
// 	}


// 	cout << lHcount*lGcount;

// }

/* --------------------SECOND SOLUTION----------------- */

// // Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int n;
// 	cin >> n;

// 	vector<char> cowsType(n);
// 	vector<int> cowsList(n);

// 	for(int i = 0; i < n; i++) {
// 		cin >> cowsType[i];
// 	}

// 	for(int i = 0; i < n; i++) {
// 		cin >> cowsList[i];
// 	}

// 	int HCount = 0, GCount = 0;

// 	for(int i = 0; i < n; i++) {
// 		if (cowsType[i] == 'H') {
// 			HCount++;
// 		} else {
// 			GCount++;
// 		}
// 	}

// 	int earlyHLeader = -1, earlyGLeader = -1;

// 	int lHcount = 0, lGcount = 0;

// 	for(int i = 0; i < n; i++) {
// 		int count = 0;
// 		for(int j = i; j < cowsList[i]; j++) {
// 			if(cowsType[i] == 'G') {
// 				if(cowsType[j] == 'G') {
// 					count++;
// 				}

// 				if(earlyGLeader < 0) {
// 					if(count == GCount) {
// 						lGcount++;
// 						earlyGLeader = i;
// 						break;
// 					}
// 				}
// 			} else {
// 				if(cowsType[j] == 'H') {
// 					count++;
// 				}

// 				if(earlyHLeader < 0) {
// 					if(count == HCount) {
// 						lHcount++;
// 						earlyHLeader = i;
// 						break;
// 					}
// 				}
// 			}
// 		}
// 	}

// 	for(int i = 0; i < n; i++) {
// 		int count = 0;
// 		for(int j = i; j < cowsList[i]; j++) {
// 			if(cowsType[i] == 'G') {
// 				if(j == earlyHLeader) {
// 					lGcount++;
// 					break;
// 				}
// 			} else {
// 				if(j == earlyGLeader) {
// 					lHcount++;
// 					break;
// 				}
// 			}
// 		}
// 	}

	
// 	cout << lHcount*lGcount;

// }

// /* ----------------------ACTUAL SOLUTION MY VERSION --------------- */


// #include <bits/stdc++.h>

// using namespace std;

// const int MAXN = 3e5 + 13;

// int ans;

// int main(){
// 	int n; string s;
// 	cin >> n >> s;
// 	vector<int> vec(n);

// 	for(int i = 0; i < n; i++) {
// 		cin >> vec[i];
// 		vec[i]--;
// 	}

// 	// Finding earliest G and H.

// 	int eG, eH;

// 	for(int i = 0; i < n; i++) {
// 		if(s[i] == 'G') {
// 			eG = i;
// 			break;
// 		}
// 	}

// 	for(int i = 0; i < n; i++) {
// 		if(s[i] == 'H') {
// 			eH = i;
// 			break;
// 		}
// 	}

// 	// Finding latest G and H;
// 	int lG, lH;

// 	for(int i = n; i > 0; i--) {
// 		if(s[i] == 'G') {
// 			lG = i;
// 			break;
// 		}
// 	}

// 	for(int i = n; i > 0; i--) {
// 		if(s[i] == 'H') {
// 			lH = i;
// 			break;
// 		}
// 	}

// 	int gLeadersCount = 0;
// 	int hLeadersCount = 0;

// 	int gLeader = -1, hLeader = -1;

// 	// if eG and eH are leaders
// 	if(vec[eG] >= lG) {
// 		gLeadersCount++;
// 		gLeader = eG;
// 	}

// 	if(vec[eH] >= lH) {
// 		hLeadersCount++;
// 		hLeader = eH;
// 	}

// 	// if any G or H are leaders by having hLeaders or gLeaders in their list.
// 	for(int i = 0; i < n; i++) {
// 		if((s[i] == 'G') && (hLeader != -1) && (vec[i] >= hLeader) && (i != gLeader) && (i < hLeader)) {
// 			gLeadersCount++;
// 		}

// 		if((s[i] == 'H') && (gLeader != -1) && (vec[i] >= gLeader) && (i != hLeader) && (i < gLeader)) {
// 			hLeadersCount++;
// 		}
// 	}

// 	cout << hLeadersCount * gLeadersCount;
// }


/* SECOND TRY */


#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	vector<int> cowsList(n);

	for(int i = 0; i < n; i++) {
		cin >> cowsList[i];
		cowsList[i]--;
	}

	int eG, eH;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'G') {
			eG = i;
			break;
		}
	}
	for(int i = 0; i < n; i++) {
		if(s[i] == 'H') {
			eH = i;
			break;
		}
	}

	int lG, lH;
	for(int i = n; i > 0; i--) {
		if(s[i] == 'G') {
			lG = i;
			break;
		}
	}
	for(int i = n; i > 0; i--) {
		if(s[i] == 'H') {
			lH = i;
			break;
		}
	}

	int hLeader, gLeader;

	
	int hLeadersCount = 0;
	int gLeadersCount = 0;

	if(cowsList[eH] >= lH) {
		hLeader = eH;
		hLeadersCount++;
	} else {
		hLeader = INT_MIN;
	}

	if(cowsList[eG] >= lG) {
		gLeader = eG;
		gLeadersCount++;
	} else {
		gLeader = INT_MIN;
	}

	for(int i = 0; i < n; i++) {
		if(s[i] == 'H' && i != hLeader) {
			if(cowsList[i] >= gLeader && gLeader != INT_MIN && i < gLeader) {
				hLeadersCount++;
			}
		}

		if(s[i] == 'G' && i != gLeader) {
			if(cowsList[i] >= hLeader && hLeader != INT_MIN && i < hLeader) {
				gLeadersCount++;
			}
		}
	}

	cout << gLeadersCount * hLeadersCount;

}

