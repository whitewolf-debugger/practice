//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        for(int i = 0 ;  i< N; i++) {
            //if we  get a room where wifi is there 
            if(S[i] == '1') {
                //move left pointer one left and right pointer one right 
                //set count to 0
                int L = i - 1;
                int R = i + 1;
                int count = 0;
                while((L >= 0 && R < N) && count < X) {
                    if(S[L] == '0' ) {
                        S[L] = '2';
                    }
                    if(S[R] == '0'){
                        S[R] = '2';
                    }
                    L--;
                    R++;
                    count++;
                }
                while(count < X && L >= 0) {
                    if(S[L] == '0' ) {
                        S[L] = '2';
                    }
                    L--;
                    count++;
                }
                while(count < X && R < N) {
                    if(S[R] == '0'){
                        S[R] = '2';
                    }
                    R++;
                    count++;
                }
            }
        }
        
        bool ans = true;
        for(int i = 0 ;  i<N; i++) {
            if(S[i] == '0') {
                ans = false;
                break;
            }
        }
        return ans;
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