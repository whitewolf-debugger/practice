//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long mod = 1e9 + 7;
    int nCr(int n, int r){
        if(r > n) return 0;
        // code here
        vector<vector<long long>> pascals(n + 1);
        for(int r = 0 ; r <= n; r++) {
            pascals[r] = vector<long long>(r + 1, 1);
            for(int c = 1; c < r; c++) {
                pascals[r][c] = (pascals[r - 1][c] + pascals[r - 1][c - 1]) % mod;
            }
        }
        return pascals[n][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends