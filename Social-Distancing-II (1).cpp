// Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int N; cin >> N;
// 	vector<vector<int>> info(N, vector<int> (2));
// 	int maxCow = 0;
// 	for(int i = 0; i < N; i++) {
// 		cin >> info[i][0] >> info[i][1];
// 		maxCow = max(maxCow, info[i][0]);
// 	}

// 	vector<char> numLine(maxCow, 'U');
// 	for(int i = 0; i < N; i++) {
// 		int state = info[i][1]; int pos = info[i][0] - 1;
// 		if(state == 1) {
// 			numLine[pos] = '1';
// 		} else {
// 			numLine[pos] = '0';
// 		}
// 	}

	
	
// }


// 1/1/2024
// #include <bits/stdc++.h>
// using namespace std;

// bool sortcol(const vector<int>& v1, const vector<int>& v2)
// {
//     return v1[0] < v2[0];
// }

// int main() {
// 	int N; cin >> N;
// 	vector<vector<int>> info(N, vector<int> (2));
// 	int maxCow = 0;
// 	for(int i = 0; i < N; i++) {
// 		cin >> info[i][0] >> info[i][1];
// 	}

// 	sort(begin(info), end(info));
	
// 	// Possible R's
// 	vector<int> possibleRs;
// 	for(int i = 0; i < N; i++) {
// 		if(info[i][1] == 0) {
// 			if(info[i+1][1] == 1) {
// 				int dist = abs(info[i+1][0] - info[i][0]);
// 				possibleRs.push_back(dist);
// 			}
// 			if(info[i-1][1] == 1) {
// 				int dist = abs(info[i-1][0] - info[i][0]);
// 				possibleRs.push_back(dist);
// 			}
// 		}
// 	}

// 	sort(begin(possibleRs), end(possibleRs));
// 	int R = possibleRs[0];

// 	int ans = 0;

// 	for(int i = 0; i < N; i++) {
// 		if(i != N-1) {
// 			int count = abs(info[i+1][0] - info[i][0]);
// 			if(info[i][1] == 1 && count > R) {
// 				ans++;
// 			}
// 		} 
// 	}

// 	cout << ans;
// }

// 1/1/2024 v2

// #include <bits/stdc++.h>
// using namespace std;

// bool sortcol(const vector<int>& v1, const vector<int>& v2)
// {
//     return v1[0] < v2[0];
// }

// int main() {
// 		freopen("socdist2.in", "r", stdin);
// 		// the following line creates/overwrites the output file
// 		freopen("socdist2.out", "w", stdout);
// 	int N; cin >> N;
// 	vector<vector<int>> info(N, vector<int> (2));
// 	int maxCow = 0;
// 	for(int i = 0; i < N; i++) {
// 		cin >> info[i][0] >> info[i][1];
// 	}

// 	sort(begin(info), end(info));
	
// 	// Possible R's
// 	vector<int> possibleRs;
// 	for(int i = 0; i < N; i++) {
// 		if(info[i][1] == 0) {
// 			if(info[i+1][1] == 1) {
// 				int dist = abs(info[i+1][0] - info[i][0]);
// 				possibleRs.push_back(dist);
// 			}
// 			if(info[i-1][1] == 1) {
// 				int dist = abs(info[i-1][0] - info[i][0]);
// 				possibleRs.push_back(dist);
// 			}
// 		}
// 	}

// 	sort(begin(possibleRs), end(possibleRs));
// 	int R = possibleRs[0];

// 	int ans = 0;

// 	int first = 0;
// 	for(int i = 0; i < N; i++) {
// 		if(info[i][1] == 1 && first == 0) {
// 			first = 1;
// 			ans++;
// 		} 
// 		if(i != N-1 && first == 1) {
// 			int count = abs(info[i+1][0] - info[i][0]);
// 			if(info[i][1] == 1 && count >= R) {
// 				ans++;
// 			}
// 		} 
// 	}

// 	cout << ans;
// }

// // 1/1/2024 v3 edge cases
// #include <bits/stdc++.h>
// using namespace std;

// bool sortcol(const vector<int>& v1, const vector<int>& v2)
// {
//     return v1[0] < v2[0];
// }

// int main() {
// 	freopen("socdist2.in", "r", stdin);
// 	// the following line creates/overwrites the output file
// 	freopen("socdist2.out", "w", stdout);

// 	int N; cin >> N;
// 	vector<vector<int>> info(N, vector<int> (2));
// 	int maxCow = 0;
// 	int ifallones = 0;
// 	int ifallzeros = 0;
// 	for(int i = 0; i < N; i++) {
// 		cin >> info[i][0] >> info[i][1];
// 		if(info[i][1] == 0) {
// 			ifallones = 1;
// 		}
// 		if(info[i][1] == 1) {
// 			ifallzeros = 1;
// 		}
// 	}

// 	// if(ifallones != 1) {
// 	// 	cout << 1;
// 	// 	return 0;
// 	// }
// 	// if(ifallzeros != 1) {
// 	// 	cout << 0;
// 	// 	return 0;
// 	// }

// 	sort(begin(info), end(info));
	
// 	// Possible R's
// 	vector<int> possibleRs;
// 	for(int i = 0; i < N; i++) {
// 		if(info[i][1] == 0) {
// 			if(info[i+1][1] == 1) {
// 				int dist = abs(info[i+1][0] - info[i][0]);
// 				possibleRs.push_back(dist);
// 			}
// 			if(info[i-1][1] == 1) {
// 				int dist = abs(info[i-1][0] - info[i][0]);
// 				possibleRs.push_back(dist);
// 			}
// 		}
// 	}

// 	sort(begin(possibleRs), end(possibleRs));
// 	int R = possibleRs[0];

// 	int ans = 0;

// 	int first = 0;
// 	for(int i = 0; i < N; i++) {
// 		if(info[i][1] == 1 && first == 0) {
// 			first = 1;
// 			ans++;
// 		} 
// 		if(i != N-1 && first == 1) {
// 			int count = abs(info[i+1][0] - info[i][0]);
// 			if(info[i][1] == 1 && count >= R) {
// 				ans++;
// 			}
// 		} 
// 	}

// 	cout << ans;
// }


// // 1/2/2024 v4 bug fixing
// #include <bits/stdc++.h>
// using namespace std;

// bool sortcol(const vector<int>& v1, const vector<int>& v2)
// {
//     return v1[0] < v2[0];
// }

// int main() {
// 	freopen("socdist2.in", "r", stdin);
// 	// the following line creates/overwrites the output file
// 	freopen("socdist2.out", "w", stdout);

// 	int N; cin >> N;
// 	vector<vector<int>> info(N, vector<int> (2));
// 	int maxCow = 0;
// 	int ifallones = 0;
// 	int ifallzeros = 0;
// 	for(int i = 0; i < N; i++) {
// 		cin >> info[i][0] >> info[i][1];
// 		if(info[i][1] == 0) {
// 			ifallones = 1;
// 		}
// 		if(info[i][1] == 1) {
// 			ifallzeros = 1;
// 		}
// 	}

// 	if(ifallones != 1) {
// 		cout << 1;
// 		return 0;
// 	}
// 	if(ifallzeros != 1) {
// 		cout << 0;
// 		return 0;
// 	}

// 	sort(begin(info), end(info));
	
// 	// Possible R's
// 	vector<int> possibleRs;
// 	for(int i = 0; i < N; i++) {
// 		if(info[i][1] == 0) {
// 			if(info[i+1][1] == 1 && i != N - 1) {
// 				int dist = abs(info[i+1][0] - info[i][0]);
// 				possibleRs.push_back(dist);
// 			}
// 			if(info[i-1][1] == 1 && i != 0) {
// 				int dist = abs(info[i-1][0] - info[i][0]);
// 				possibleRs.push_back(dist);
// 			}
// 		}
// 	}

// 	sort(begin(possibleRs), end(possibleRs));
// 	int R = possibleRs[0];

// 	int ans = 0;

// 	int first = 0;
// 	for(int i = 0; i < N; i++) {
// 		if(info[i][1] == 1 && first == 0) {
// 			first = 1;
// 			ans++;
// 		} 
// 		if(i != N-1 && first == 1) {
// 			int count = abs(info[i+1][0] - info[i][0]);
// 			if(info[i][1] == 1 && count >= R) {
// 				ans++;
// 			}
// 		} 
// 	}

// 	cout << ans;
// }

// // 1/2/2024 gpt
// #include <bits/stdc++.h>
// using namespace std;

// bool sortcol(const vector<int>& v1, const vector<int>& v2) {
//     return v1[0] < v2[0];
// }

// int main() {
//     freopen("socdist2.in", "r", stdin);
//     freopen("socdist2.out", "w", stdout);

//     int N;
//     cin >> N;
//     vector<vector<int>> info(N, vector<int>(2));
//     int ifallones = 0;
//     int ifallzeros = 0;

//     for (int i = 0; i < N; i++) {
//         cin >> info[i][0] >> info[i][1];
//         if (info[i][1] == 0) {
//             ifallones = 1;
//         }
//         if (info[i][1] == 1) {
//             ifallzeros = 1;
//         }
//     }

//     if (ifallones != 1) {
//         cout << 1;
//         return 0;
//     }
//     if (ifallzeros != 1) {
//         cout << 0;
//         return 0;
//     }

//     sort(begin(info), end(info));

//     vector<int> possibleRs;
//     for (int i = 1; i < N; i++) {
//         if (info[i][1] == 0 && info[i - 1][1] == 1) {
//             int dist = abs(info[i][0] - info[i - 1][0]);
//             possibleRs.push_back(dist);
//         }
//     }

//     sort(begin(possibleRs), end(possibleRs));
//     int R = possibleRs[0];

//     int ans = 0;
//     for (int i = 0; i < N; i++) {
//         if (info[i][1] == 1) {
//             ans++;
//             int j = i + 1;
//             while (j < N && abs(info[j][0] - info[i][0]) < R) {
//                 j++;
//             }
//             i = j - 1;
//         }
//     }

//     cout << ans;
//     return 0;
// }

// 1/3/2024 fixed bool and possibeleRs boundaries and adding to ans process.
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("socdist2.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("socdist2.out", "w", stdout);

	int N; cin >> N;
	vector<vector<int>> info(N, vector<int> (2));
	int maxCow = 0;
	bool allones = true, allzeros = true;
	for(int i = 0; i < N; i++) {
		cin >> info[i][0] >> info[i][1];
		
		if(info[i][1] == 0) {
			allones = false;
		}
		if(info[i][1] == 1) {
			allzeros = false;
		}
	}

	if(allones) {
		cout << 1; return 0;
	}
	if(allzeros) {
		cout << 0; return 0;
	}

	sort(begin(info), end(info));
	
	// Possible R's
	vector<int> possibleRs;
	for(int i = 0; i < N; i++) {
		if(info[i][1] == 0) {
			if(i != N - 1) {
				if(info[i+1][1] == 1) {
					int dist = abs(info[i+1][0] - info[i][0]);
					possibleRs.push_back(dist);
				}
			}
			if(i != 0) {
				if(info[i-1][1] == 1 && i != 0) {
					int dist = abs(info[i-1][0] - info[i][0]);
					possibleRs.push_back(dist);
				}
			}
		}
	}

	sort(begin(possibleRs), end(possibleRs));
	int R = possibleRs[0];

	int ans = 0;

	int first = 0;
	for(int i = 1; i < N; i++) {
		if(info[i][1] == 1 && first == 0) {
			first = 1;
			ans++;
		}
		if(first == 1) {
			int count = abs(info[i][0] - info[i-1][0]);
			if(info[i][1] == 1 && count >= R) {
				ans++;
			}
		}
	}

	cout << ans;
}
