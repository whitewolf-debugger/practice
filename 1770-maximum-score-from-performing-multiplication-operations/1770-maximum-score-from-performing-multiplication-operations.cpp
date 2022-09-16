class Solution {
public:
    int dp(vector<int> &nums,vector<int> & multipliers,int right, int left,int i,vector<vector<int>> &cache){
        if(i >= multipliers.size()){
            return 0;
        }
        if(cache[i][left] != INT_MIN) return cache[i][left];
        int l =  multipliers[i]*nums[left] + dp(nums,multipliers,right,left+1,i+1,cache);
        int r =  multipliers[i]*nums[right] + dp(nums,multipliers,right-1,left,i+1,cache);
        return cache[i][left] = max(l,r);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> cache(m + 1,vector<int>(m + 1,INT_MIN));
        return dp(nums,multipliers,n-1,0,0,cache);
    }
};