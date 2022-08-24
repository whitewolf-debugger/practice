class Solution {
public:
    long long dp(vector<int>& nums,int index,vector<int>& cache){
        
        //if we are at the end return return 0
        if(index >= nums.size()-1){
            return 0;
        }
        
        //memoization step using cache 
        if(cache[index] != -1) return cache[index];
        
        //ans stores the minimum step
        long long ans = INT_MAX;
        
        for(int i =1; i <= nums[index]; i++){
            
            //move stores the moves it takes if we take 'i' step 
            long long move = 1+dp(nums,index+i,cache);
            //we want minimum of those steps
            ans = min(ans,move);
        }
        
        //memoization 
        return cache[index] = ans;
    }
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> cache(n,-1);
            
        return dp(nums,0,cache);
    }
};