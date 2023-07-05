//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int dp(int n, vector<int> &prices ,bool buy, int i,vector<vector<int>> &cache) {
        //base case when the index i exceeds the price array then we simply return -
        if(i >= prices.size()) {
            return false;
        }
        //memoization step
        if(cache[buy][i] != -1) return cache[buy][i];
        //we can buy only when buy is true
        int ans = 0;
        //====================================================================================
        //case 1 we buy or sell based on bool buy since we can hold only one stock at a time 
        if(buy) {
            //when we buy , bool buy becomes 0 that means now we have to sell 
            ans += -prices[i] + dp(n,prices,0,i + 1,cache);
        }
        else {
            //when we sell , bool buy becomes 1 that means now we have to buy
            ans += prices[i] + dp(n,prices,1,i + 1,cache);
        }
        //====================================================================================
        //case 2 do nothing moveq forward  ans is max of case 1 and case 2
        ans = max(ans, dp( n+ 1, prices,buy,i + 1,cache));
        //===================================================================================
        return cache[buy][i] = ans;
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        vector<vector<int>> cache(2,vector<int>(n + 1, -1));
        int ans = dp(n,prices,1,0,cache);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends