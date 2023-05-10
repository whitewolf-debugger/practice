//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        int count = 0;
        vector<int> left(N,0);
        vector<int> right(N,INT_MAX);
        left[0] = A[0];
        for(int i =1; i < N; i++) {
            left[i] = max(left[i-1], A[i]);
        }
        right[N-1] = A[N-1];
        for(int i = N - 2; i >= 0 ; i--) {
            right[i] = min(right[i + 1] ,A[i]);
        }
        for(int i = 1 ; i < N; i++) {
            if((left[i - 1] + right[i]) >= K) {
                count++;
            }
        }
        return count;
    }
};
/*


    1     2      3    4   5
                        
  {1,1} {1,2}  {1,3} {1,4} {1,5}
        
    
    
              


*/

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends