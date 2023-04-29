//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    long long findNumber(long long N) {
        N -= 1;
        long long dig = 1;
        while (N >= pow(5, dig)) {
            N -= pow(5, dig);
            dig += 1;
        }
        
        string ret = "";
        for (int i = dig-1; i >= 0; i--) {
            long long pw = pow(5, i);
            long long k = N / pw;
            ret += to_string(2*k+1);
            N -= pw * k;
        }
        return stoll(ret);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends