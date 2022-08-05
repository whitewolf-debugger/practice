class Solution {
public:
    int dfs(vector<int>& nums,int k,vector<int> & cache){
        if(k==0){
            return 1;
        }
        if(cache[k]!=-1)return cache[k];
        int howmanyWays =0;
        for(auto x: nums){
            if(k>=x){
                howmanyWays+=dfs(nums,k-x,cache);
            }
        }
        return cache[k] = howmanyWays;
    }
    int combinationSum4(vector<int>& nums, int target) {
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