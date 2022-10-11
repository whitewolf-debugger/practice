class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        bool Left = false, Right = false , Middle = false;
        int l = INT_MAX;
        int r = INT_MAX;
        int mid = INT_MAX;
        for(int i =0; i < n;i++) {
            if(l > nums[i]) {
                l  = nums[i];
                Left = true;
            }
            if(nums[i] > l && nums[i] < mid) {
                mid= nums[i];
                Middle = true;
            }
            if(nums[i] > mid && nums[i] <= r){
                r = nums[i];
                Right = true;
            }
            if(Left && Right && Middle) return true;
        }
        return false;
    }
};