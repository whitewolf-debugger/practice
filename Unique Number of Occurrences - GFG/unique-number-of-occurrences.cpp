//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        bool ans = true;
        unordered_map<int , int> numFreq;
        unordered_map<int , int> freq;
        set<int> no;
        for(int i = 0 ; i < n; i++) {
            numFreq[arr[i]]++;
            no.insert(arr[i]);
        }
        for(auto x : no) {
            freq[numFreq[x]]++;
        }
        for(auto x:freq) {
            if(x.second > 1) {
                ans = false;
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends