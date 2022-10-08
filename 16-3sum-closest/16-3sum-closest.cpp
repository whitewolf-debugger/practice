class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int n = nums.size();
       int ans= -1;
       int diff = INT_MAX;
       sort(nums.begin(),nums.end());
       for(int i =0 ; i < n;i++) {
           int lo = i+1;
           int hi = n-1;
           while(lo < hi){
               int sum = nums[i] + nums[lo] + nums[hi];
               if(abs(target - sum) < abs(diff)) {
                   diff = target - sum;
                   ans = sum;
               }
               if(sum > target){
                   hi--;
               } else {
                   lo++;
               }
           }
       }
       return ans;
    }
};
/*
Initialize the minimum difference diff with a large value.
Sort the input array nums.
Iterate through the array:
For the current position i, set lo to i + 1, and hi to the last index.
While the lo pointer is smaller than hi:
Set sum to nums[i] + nums[lo] + nums[hi].
If the absolute difference between sum and target is smaller than the absolute value of diff:
Set diff to target - sum.
If sum is less than target, increment lo.
Else, decrement hi.
If diff is zero, break from the loop.
Return the value of the closest triplet, which is target - diff.

*/