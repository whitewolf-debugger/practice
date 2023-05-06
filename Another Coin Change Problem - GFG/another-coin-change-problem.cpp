//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool dp(vector<int> &coins, int target, int k, int i, vector<vector<vector<int>>> & cache) {
        // if we exceed the number coins array and unable to make the change then return false
        if(i >= coins.size()) return false;
        //memoization step
        if(cache[i][k][target] != -1) return cache[i][k][target];
        //if we used all the k coins 
        if(k == 0) {
            //if we are able to achieve the target then return true
            if(target == 0) return true;
            return false;
        }
        
        bool take= false, notTake = false;
        //take if target (remaining amount) is more than the current coin denomination
        // donot do i + 1 since  we have= infinite supply of each coin
        //so we try to take larger denominations till we can 
        if(target >= coins[i]) {
            take = take || dp(coins,target-coins[i],k-1,i,cache);
        } 
        //not take condition move to next coin
        notTake = notTake || dp(coins,target,k,i+1,cache);
        //memoization
        return cache[i][k][target]=(take || notTake);
         
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<vector<int>>> cache(N + 1, vector<vector<int>>(K + 1,vector<int>(target + 1, -1)));
        //sorted in descending order since we start making change from higher denomination
        //like if we want to make 21 and we haver 10 5 and 1 
        //then we start taking coin of denomination 10
        sort(coins.rbegin(),coins.rend());
        bool ans = dp(coins, target, K, 0,cache);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends