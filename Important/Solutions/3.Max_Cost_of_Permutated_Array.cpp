#include <bits/stdc++.h>
using namespace std;

int maximumCost(int N, vector<int>& A, vector<int>& B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = 0, j = 0, cost = 0;
    
    // Greedy two-pointer approach
    while (i < N && j < N) {
        if (A[i] > B[j]) {
            cost++;
            i++;
            j++;
        } else {
            i++;
        }
    }
    
    return cost;
}

int main() {
    // Example 1
    int N = 3;
    vector<int> A = {3, 1, 2};
    vector<int> B = {2, 3, 1};
    cout << maximumCost(N, A, B) << endl;  // Output: 2
    
    // Example 2
    N = 5;
    A = {5, 4, 3, 2, 1};
    B = {1, 2, 3, 4, 5};
    cout << maximumCost(N, A, B) << endl;  // Output: 4

    return 0;
}
