class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        bool Left = false, Right = false , Middle = false;
        int l = INT_MAX ,  r = INT_MAX , mid = INT_MAX;
        for(int i =0; i < n;i++) {
            // we want the left pinter to be placed at the minimum element 
            if(l > nums[i]) {
                l  = nums[i];
                Left = true;
            }
            //we want the middle pointer to be placed at the element greater than left element 
            if(nums[i] > l && nums[i] < mid) {
                mid= nums[i];
                Middle = true;
            }
            //we want the right to be placed at the poisition of element greater than the mid element 
            if(nums[i] > mid && nums[i] <= r){
                r = nums[i];
                Right = true;
            }
            if(Left && Right && Middle) return true;
        }
        return false;
    }
};