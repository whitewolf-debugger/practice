class Solution {
public:
    //like knapsack style solution 
    int dfs(vector<int>& nums,int k,vector<int> & cache){
        //if k==0 means we have our target
        if(k==0){
            //return 1
            return 1;
        }
        //return cache of its already there (memoization)
        if(cache[k]!=-1)return cache[k];
        int howmanyWays =0;
        //x is nums 
        for(auto x: nums){
            //if(k>=x) we do dfs get the combination
            if(k>=x){
                howmanyWays+=dfs(nums,k-x,cache);
            }
        }
        //cache the ways we got 
        return cache[k] = howmanyWays;
    }
    int combinationSum4(vector<int>& nums, int target) {
        //memoization of the solution 
        vector<int>  cache(target+1,-1);
        vector<int> v;
        int ans = dfs(nums,target,cache);
        return ans;
    }
};
/*

 [1 , 2 , 3 ]

  dfs(int k ,)
  if(k==0) return 1
  



*/