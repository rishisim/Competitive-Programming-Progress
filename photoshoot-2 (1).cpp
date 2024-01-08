// // Source: https://usaco.guide/general/io

// #include <bits/stdc++.h>
// using namespace std;

// int diffChange()

// int main() {
// 	int n; cin >> n;
// 	vector<int> initial(n), goal(n);
// 	for(int i = 0; i < n; i++) cin >> initial[i];
// 	for(int i = 0; i < n; i++) cin >> goal[i];

// 	for(int i = n - 1; i >= 0; i--) {
// 		if(initial[i] != goal[i]) {
// 			diffCount = 
// 			i = n - 1;
// 		}
// 	}
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
// 	int n; cin >> n;
// 	vector<int> initial(n), goal(n);
// 	for(int i = 0; i < n; i++) cin >> initial[i];
// 	for(int i = 0; i < n; i++) cin >> goal[i];

// 	int changes = 0;

// 	for(int i = 0; i < n; i++) {
// 		if(initial[i] != goal[i]) {
// 			auto it = find(begin(initial), end(initial), goal[i]);
// 			for(int j = 0; j < n; j++) {
// 				if(j == i) {
// 					initial[it] = goal[j];
// 				} else {
// 					if(initial[i] != goal[i]) {
// 						initial[i] = initial[i-1];
// 					}
// 				}
// 			}
// 			changes++;
// 		}
// 	}

// 	cout << changes;

// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int N;
//     cin >> N;
//     vector<int> A(N), B(N);
//     for (int i = 0; i < N; i++) {
//         cin >> A[i];
//     }
//     for (int i = 0; i < N; i++) {
//         cin >> B[i];
//     }

//     vector<int> need_to_move(N, 0);

//     auto pos_in_B = & {
//         for (int i = 0; i < N; i++) {
//             if (B[i] == x) {
//                 return i;
//             }
//         }
//         return -1;
//     };

//     for (int i = 0; i < N; i++) {
//         for (int j = i + 1; j < N; j++) {
//             if (pos_in_B(A[i]) > pos_in_B(A[j])) {
//                 need_to_move[j] = 1;
//             }
//         }
//     }

//     cout << accumulate(need_to_move.begin(), need_to_move.end(), 0) << endl;

//     return 0;
// }

#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N), need_to_move(N, 0);

    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    auto pos_in_B = [&B](int x) {
        for (int i = 0; i < B.size(); ++i) {
            if (B[i] == x) {
                return i;
            }
        }
        return -1; // Handle the case when the element is not found in B
    };

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (pos_in_B(A[i]) > pos_in_B(A[j])) {
                need_to_move[j] = 1;
            }
        }
    }

    int result = 0;
    for (int i : need_to_move) {
        result += i;
    }

    std::cout << result << std::endl;

    return 0;
}
