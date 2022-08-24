class Solution {
public:
    long long dp(vector<int>& nums,int index,vector<int>& cache){
        if(index >= nums.size()-1){
            return 0;
        }
        
        if(cache[index] != -1) return cache[index];
        long long ans = INT_MAX;
        for(int i =1; i <= nums[index]; i++){
            long long move = 1+dp(nums,index+i,cache);
            ans = min(ans,move);
        }
        return cache[index] = ans;
    }
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> cache(n,-1);
            
        return dp(nums,0,cache);
    }
};