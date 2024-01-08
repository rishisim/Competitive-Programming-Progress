// // Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int num;
// 	cin >> num;
// 	vector<char> A(num);
// 	vector<char> B(num);

// 	for(int i = 0; i < num; i++) {
// 		cin >> A[i];
// 	}
// 	for(int i = 0; i < num; i++) {
// 		cin >> B[i];
// 	}

// 	int count = 0;
// 	int flips = 0;
// 	bool diff;
// 	for(int i = 0; i < num; i++) {
// 		if(A[i] != B[i]) {
// 			diff = true;
// 		} else {
// 			diff = false;
// 		}

// 		if(diff == true) {
// 			if(count >= 0) {
// 				count++;
// 			}
// 		} else {
// 			if(count > 0) {
// 				flips++;
// 				count = 0;
// 			}
// 		}
// 	}

// 	cout << flips;
// }

// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("breedflip.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("breedflip.out", "w", stdout);


	int N;
	cin >> N;

	string a, b;
	cin >> a >> b;

	int count = 0;
	int flips = 0;
	for(int i = 0; i < N; i++) {
		if(a[i] != b[i]) {
			count++;
		} else {
			count = 0;
		}

		if((count > 0) && (i < N - 1) && (a[i+1] == b[i+1])) {
			flips++;
		} else if ((count > 0) && (i == N - 1)) {
			flips++;
		} else {
			count = 0;
		}
	}

	cout << flips;
}
