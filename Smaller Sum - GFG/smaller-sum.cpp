//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<long long> ans;
        vector<long long> a(arr.begin(),arr.end());
        sort(a.begin(), a.end());
        vector<long long> v(n);
        v[0] = 0;
        for(int i = 1 ; i < n; i++) {
            v[i] = v[i-1] + a[i-1];
        }
        for(int i = 0 ; i < n; i++) {
            long long val = arr[i];
            auto it = lower_bound(a.begin(),a.end(),val);
            int idx = it - a.begin();
            ans.push_back(v[idx]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends