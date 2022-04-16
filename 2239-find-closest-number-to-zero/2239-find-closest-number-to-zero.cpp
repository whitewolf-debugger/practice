class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int min =INT_MAX;
        int ans;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])<=min){
                ans = nums[i] ;
                min = abs(nums[i]);
            }
        }
        return ans;
    }
};