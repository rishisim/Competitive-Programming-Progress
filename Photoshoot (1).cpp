// Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int N; cin >> N;
// 	string str; cin >> str;

// 	int length = N;
// 	for(int i = 0; i < N/2 + 1; i++) {
// 		int evenGCount = 0;
// 		string strCopy = str;
// 		reverse(begin(strCopy), end(strCopy) - length);
// 		for(int j = 0; j < N; j++) {
// 			if((strCopy[j] == 'G') && ((j+1)%2 == 0)) evenGCount++;
// 		}
// 		cout << strCopy << " Gcount: " << evenGCount << "\n";
// 		length -= 2;
// 	}
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int N; cin >> N;
// 	string str; cin >> str;

// 	vector<string> simplifystr;

// 	for(int i = 0; i < N - 1; i++) {
// 		if((i+1)%2 != 0) {
// 			if(str.substr(i, 2) == "GG" || str.substr(i, 2) == "HH") {
// 				continue;
// 			} else if (str.substr(i, 2) == "HG") {
// 				if(simplifystr.size() > 0) {
// 					if(simplifystr[size(simplifystr) - 1] != "T") {
// 						simplifystr.push_back("T");
// 					}
// 				} else {simplifystr.push_back("T");}
// 			} else {
// 				if(simplifystr.size() > 0) {
// 					if(simplifystr[size(simplifystr) - 1] != "F") {
// 						simplifystr.push_back("F");
// 					}
// 				} else {simplifystr.push_back("F");}
// 			}
// 		}
// 	}

// 	if(simplifystr[size(simplifystr) - 1] == "T") {
// 		cout << simplifystr.size()-1;
// 	} else {
// 		cout << simplifystr.size();
// 	}

// 	// auto last = unique(simplifystr.begin(), simplifystr.end());
// 	// simplifystr.erase(last, simplifystr.end());

// 	// cout << simplifystr.size();
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	string str; cin >> str;

	vector<string> simplifystr;

	for(int i = 0; i < N - 1; i+=2) {
		string sub = str.substr(i, 2);
		if(sub == "GG" || sub == "HH") {
			continue;
		} else if (sub == "HG") {
			if(simplifystr.size() > 0) {
				if(simplifystr[size(simplifystr) - 1] != "T") {
					simplifystr.push_back("T");
				}
			} else {simplifystr.push_back("T");}
		} else {
			if(simplifystr.size() > 0) {
				if(simplifystr[size(simplifystr) - 1] != "F") {
					simplifystr.push_back("F");
				}
			} else {simplifystr.push_back("F");}
		}
	}

	if(simplifystr[size(simplifystr) - 1] == "T") {
		cout << simplifystr.size()-1;
	} else {
		cout << simplifystr.size();
	}

	// auto last = unique(simplifystr.begin(), simplifystr.end());
	// simplifystr.erase(last, simplifystr.end());

	// cout << simplifystr.size();
}