// // Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int N; cin >> N;
// 	vector<char> cows(N);

// 	for(int i = 0; i < N; i++) {
// 		cin >> cows[i];
// 	}

// 	// for(int i = 0; i < N; i++) {
// 	// 	cout << cows[i] << " ";
// 	// }

	

// 	int len = 3;
// 	for(int i = 0; i < N-2; i++) {
// 		for(int j = 0; j < N - len + 1; j++) {
			
// 		}
// 		cout << "\n";
// 		len++;
// 	}
// }

// Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int N; cin >> N;
// 	string str; cin >> str;

// 	int trash = 0;

// 	int len = 3;
// 	for(int i = 0; i < N-2; i++) {
// 		for(int j = 0; j < N - len + 1; j++) {
// 			string subs = str.substr(j, len);
// 			int cH = count(subs.begin(), subs.end(), 'H');
// 			int cG = count(subs.begin(), subs.end(), 'G');

// 			if(cH == 1 || cG == 1) {
// 				trash++;
// 			}
// 			// cout << str.substr(j, len) << " " << "H, G:" << cH << " " << cG << "\n";
// 		}
// 		// cout << "\n";
// 		len++;
// 	}

// 	cout << trash;
// }


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int N; cin >> N;
// 	string str; cin >> str;

// 	int trash = 0;

// 	int len = 3;
// 	for(int i = 0; i < N-2; i++) {
// 		for(int j = 0; j < N - len + 1; j++) {
			
// 		}
// 		// cout << "\n";
// 		len++;
// 	}

// 	cout << trash;
// }


// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     string breeds;
//     cin >> breeds;

//     vector<string> substrs;
//     int length = 2;

//     for (int i = 0; i < n; i++){
//         length++;
//         for (int j = 0; j < n - length + 1; j++){
//             substrs.push_back(breeds.substr(j, length));
//             // cout << breeds.substr(j, length) << " ";
//         }
//     }

//     // string copy;
//     int loners = 0;
//     int Hcounter = 0;
//     int Gcounter = 0;

//     for (int i = 0; i < substrs.size(); i++){
//         // copy = substrs[i];
//         Hcounter = 0;
//         Gcounter = 0;
//         for (int j = 0; j < substrs[i].size(); j++){
//             if (substrs[i][j] == 'H'){
//                 Hcounter++;
//             } else {
//                 Gcounter++;
//             }

//             if (j == substrs[i].size() - 1){
//                 if (Hcounter == 1 || Gcounter == 1){
//                     loners++;
//                 }
//             }
//         }
//     }

//     cout << loners;

//     // for (string substr : substrs) {
//     //     cout << substr << endl;
//     // }
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	string str; cin >> str;

	int trash = 0;
	for(int i = 0; i < N; i++) {
        int h = 0;
        int g = 0;
		for(int j = i; j < N; j++) {
			if(str[j] == 'H') {h++;}
            else {g++;}

            if(g+h >= 3 && (h == 1 || g == 1)) {
                trash++;
            }
		}
	}

	cout << trash;
}
