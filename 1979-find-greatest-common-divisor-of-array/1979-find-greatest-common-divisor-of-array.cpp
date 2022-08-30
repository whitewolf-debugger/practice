class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        
        return __gcd(nums[0], nums[nums.size() - 1]);

        
    }
};