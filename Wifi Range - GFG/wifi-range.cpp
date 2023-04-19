//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        string a=S;
        for(int i=0;i<N;i++){
            if(S[i]=='1'){
                for(int j=i-X;j<=i+X;j++){
                    if(j>=0 && j<N){
                        a[j]=1;
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            if(a[i]=='0'){
                return false;
            }
        }
        return true;

    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends