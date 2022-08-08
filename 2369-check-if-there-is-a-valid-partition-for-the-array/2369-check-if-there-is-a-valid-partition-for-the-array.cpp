class Solution {
public:
    bool dfs(vector<int> & nums,int i,vector<int> &cache){
        if(i == nums.size()) return true;
        if(i> nums.size()) return false;
        
        if(cache[i] != -1) return cache[i];
        
        bool  dups = false;
        bool trips = false;
        bool  str = false;
        
        int n = nums.size();
        
        if(i + 1 < n && nums[i] == nums[i+1]){
            dups = dfs(nums , i+2 ,cache);
        }
        
        if(i + 2 < n && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]){
            trips = dfs(nums , i+3 ,cache);
        }
        
        if(i + 2 < n && nums[i] + 1 == nums[i+1] && nums[i+1] + 1 == nums[i+2]){
            str = dfs(nums , i+3 ,cache);
        }
        
         return cache[i] = dups || trips || str;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, -1);
        return dfs(nums, 0, cache);
    }
    /*
    
    
    nums = [4,4,4,5,6]
                 LR
   s2 true
   s3 true
   
   
    
    
    */
    
};