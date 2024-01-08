// // Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int N, Q;
// 	cin >> N >> Q;

// 	vector<tuple<int, int, int>> cows(N, tuple<int,int,int> {0,0,0});
// 	for(int i = 0; i < N; i++) {
// 		int type;
// 		cin >> type;
// 		tie()
// 	}

// 	vector<tuple<int, int, int>> psum(N+1, tuple<int,int,int> {0,0,0});

// 	psum[0] = {0,0,0};
// 	for(int i = 1; i < N+1; i++) {
// 		get<0>(psum[i]) = get<0>(psum[i-1]) + get<0>(cows[i-1]);
// 		get<1>(psum[i]) = get<1>(psum[i-1]) + get<1>(cows[i-1]);
// 		get<2>(psum[i]) = get<2>(psum[i-1]) + get<2>(cows[i-1]);
// 	}


// 	for(int i = 0; i < N + 1; i++) {
// 		cout << get<0>(psum[i]) << get<1>(psum[i]) << get<2>(psum[i]);
// 	}
// }

// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("bcount.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("bcount.out", "w", stdout);

	int N, Q;
	cin >> N >> Q;

	vector<vector<int>> cows(N, vector<int> (3, 0));
	for(int i = 0; i < N; i++) {
		int type;
		cin >> type; type--;

		cows[i][type] = 1;
	}

	vector<vector<int>> psum(N+1, vector<int> (3, 0));

	psum[0][0] = 0; psum[1][0] = 0; psum[2][0] = 0;
	for(int i = 1; i < N+1; i++) {
		psum[i][0] = psum[i-1][0] + cows[i-1][0];
		psum[i][1] = psum[i-1][1] + cows[i-1][1];
		psum[i][2] = psum[i-1][2] + cows[i-1][2];
	}


	// for(int i = 0; i < N + 1; i++) {
	// 	cout << psum[i][0] << psum[i][1] << psum[i][2] << "\n";
	// }

	for(int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;

		int H, G, J;
		H = psum[b][0] - psum[a-1][0];
		G = psum[b][1] - psum[a-1][1];
		J = psum[b][2] - psum[a-1][2];

		cout << H << " " << G << " " << J << "\n";
	}
}
