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