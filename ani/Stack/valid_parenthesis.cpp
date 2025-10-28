#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(char c : s) {

        // If it's an opening bracket → push it
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else {
            // If closing bracket appears but stack is empty → invalid
            if(st.empty()) return false;

            // Check if top element matches
            if((c == ')' && st.top() == '(') ||
               (c == '}' && st.top() == '{') ||
               (c == ']' && st.top() == '[')) 
            {
                st.pop(); // Pop only when there is a correct match
            } 
            else {
                return false; // Mismatch → invalid
            }
        }
    }

    // If stack empty → all brackets matched
    return st.empty();
}

int main() {
    string s;
    cin >> s;

    if(isValid(s)) cout << "Valid";
    else cout << "Invalid";
}
