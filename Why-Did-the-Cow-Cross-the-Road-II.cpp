// // Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	// freopen("circlecross.in", "r", stdin);
// 	// // the following line creates/overwrites the output file
// 	// freopen("circlecross.out", "w", stdout);

// 	string str; cin >> str;
// 	int pairs = 0;
// 	for(int i = 0; i < 26; i++) {
// 		char charac = str[i];
// 		vector<char> possible;
// 		int endpos = 0;
// 		for(int j = i + 1; j < 52 - i; j++) {
// 			endpos = j;
// 			if(str[j] == charac) {
// 				break;
// 			}
// 			possible.push_back(str[j]);
// 		}
// 		sort(begin(possible), end(possible));
// 		auto last = std::unique(possible.begin(), possible.end());
// 		// v now holds {1 2 1 3 4 5 4 x x x}, where 'x' is indeterminate
// 		possible.erase(last, possible.end());

// 		for(int x = endpos + 1; x < 52 - endpos; x++) {
// 			for(int y = 0; y < possible.size(); y++) {
// 				if(str[x] == possible[y]) pairs++;
// 			}
// 		}
// 	}

// 	cout << pairs;
// }

// // Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	// freopen("circlecross.in", "r", stdin);
// 	// // the following line creates/overwrites the output file
// 	// freopen("circlecross.out", "w", stdout);

// 	string str; cin >> str;
// 	int pairs = 0;
// 	for(int i = 0; i < 26; i++) {
// 		char charac = str[i];
// 		vector<char> possible;
// 		int endpos = 0;
// 		for(int j = i + 1; j < 52; j++) {
// 			endpos = j;
// 			if(str[j] == charac) {
// 				break;
// 			}
// 			possible.push_back(str[j]);
// 		}
// 		sort(begin(possible), end(possible));
// 		auto last = std::unique(possible.begin(), possible.end());
// 		// v now holds {1 2 1 3 4 5 4 x x x}, where 'x' is indeterminate
// 		possible.erase(last, possible.end());

// 		for(int x = endpos + 1; x < 52; x++) {
// 			for(int y = 0; y < possible.size(); y++) {
// 				if(str[x] == possible[y]) pairs++;
// 			}
// 		}
// 	}

// 	cout << pairs;
// }



// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	// freopen("circlecross.in", "r", stdin);
	// // the following line creates/overwrites the output file
	// freopen("circlecross.out", "w", stdout);

	string str; cin >> str;
	int pairs = 0;

	for(int a = 0; a < str.size(); a++) for(int b = a+1; b < str.size(); b++) for(int c = b+1; c < str.size(); c++) for(int d = c+1; d < str.size(); d++) {
		pairs += (str[a] == str[c] && str[b] == str[d]);
	}
	cout << pairs;
}

