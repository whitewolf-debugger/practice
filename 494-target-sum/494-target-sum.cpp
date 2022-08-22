class Solution {
public:
    int dfs(vector<int>& nums,int target,int i,int sum){
        if(i == nums.size()){
            if(sum == target) return 1;
            return 0;
        } else{
            int add = dfs(nums, target, i + 1, sum + nums[i]);
            int subtract = dfs(nums,target,i+1,sum - nums[i]);
            return add + subtract;
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums,target,0,0);
    }
};