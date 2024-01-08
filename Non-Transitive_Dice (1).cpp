// // Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// using Die = array<int, 4>;

// bool beats(const Die& a, const Die& b) {
// 	int wins = 0;
// 	int losses = 0;
// 	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) {
// 		if(a[i] > b[j]) wins++;
// 		if(a[i] < b[j]) losses++;
// 	}

// 	return wins > losses;
// }

// bool nontransitive(const Die& A, const Die& B) {
// 	for(int a = 0; a < 10; a++) for(int b = 0; b < 10; b++) for(int c = 0; c < 10; c++) for(int d = 0; d < 10; d++) {
// 		Die C{a, b, c, d};
// 		if(beats(A, B) && beats(B, C) && beats(C, A)) return true;
// 		if(beats(B, A) && beats(A, C) && beats(C, B)) return true;
// 	}
// 	return false;
// }


// int main() {
// 	int N; cin >> N;
// 	for(int i = 0; i < N; i++) {
// 		Die A, B;
// 		for(int j = 0; j < N; j++) cin >> A[j];
// 		for(int j = 0; j < N; j++) cin >> B[j];
// 		if(nontransitive(A, B)) {
// 			cout << "yes\n";
// 		} else {
// 			cout << "no\n";
// 		}
// 	}
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;

using Die = array<int, 4>;

bool beats(const Die& a, const Die& b) {
	int wins = 0;
	int losses = 0;
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) {
		if(a[i] > b[j]) wins++;
		if(a[i] < b[j]) losses++;
	}
	return wins > losses;
}

bool nonTransitive(const Die& A, const Die& B) {
	for(int a = 1; a <= 10; a++) for(int b = 1; b <= 10; b++) for(int c = 1; c <= 10; c++) for(int d = 1; d <= 10; d++) {
		Die C{a, b, c, d};
		if(beats(A, B) && beats(B, C) && beats(C, A)) return true;
		if(beats(B, A) && beats(A, C) && beats(C, B)) return true;
	}
	return false;
}

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) {
		Die A, B;
		for(int j = 0; j < 4; j++) cin >> A[j];
		for(int j = 0; j < 4; j++) cin >> B[j];
		if(nonTransitive(A, B)) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
}