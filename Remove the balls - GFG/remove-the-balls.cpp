//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<pair<int ,int>> st;
        for(int i = 0 ; i < N; i++) {
            if(!st.empty() && st.top().first == color[i] && st.top().second == radius[i]) {
                st.pop();
                
            } 
            else{
                st.push({color[i],radius[i]});
            }
        }
        int ans = 0;
        while(!st.empty()) {
            ans++;
            st.pop();
        }
        return ans;
    }
};
/*

15
    31 6  3  48 84 18 57 73 4  4  73 4  4  4  4
    53 23 44 61 96 1  97 15 83 97 97 97 83 97 97
    
    31 6  3  48
    53 23 44 61

*/

//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends