
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int suffixQueries(string S, vector<string> &queries) {
    int N = S.size();

    // Step 1: Generate all suffixes
    vector<string> suffixes;
    for (int i = 0; i < N; i++) {
        suffixes.push_back(S.substr(i));
    }

    // Step 2: Sort all suffixes lexicographically
    sort(suffixes.begin(), suffixes.end());

    long long total = 0;  // store sum of all query results

    // Step 3: For each query
    for (string q : queries) {
        vector<string> matching;

        // Step 4: Check all suffixes and collect those starting with q
        for (string suf : suffixes) {
            if (suf.rfind(q, 0) == 0) { // starts with q
                matching.push_back(suf);
            }
        }

        // Step 5: If found any, pick the smallest (first one after sorting)
        if (!matching.empty()) {
            string smallest = matching[0];
            int len = smallest.length();
            total = (total + len) % MOD;
        } 
        // If no match → contributes 0, so do nothing
    }

    // Step 6: Return final sum modulo 1e9+7
    return (int)total;
}

int main() {
    string S = "ktmrgjswhwxu";
    vector<string> queries = {"z", "w"};

    cout << suffixQueries(S, queries) << endl;  // Output: 5

    S = "mzadpoghyykht";
    queries = {"yk"};
    cout << suffixQueries(S, queries) << endl;  // Output: 4    
    

    return 0;
}