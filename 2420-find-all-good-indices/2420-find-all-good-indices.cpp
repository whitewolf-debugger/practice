class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftDp(n,0);
        vector<int> rightDp(n,0);
        for(int l =1; l< n; l++) {
            if(nums[l] <= nums[l-1]){
               leftDp[l] = leftDp[l-1]  + 1; 
            }
        }
        for(int r = n-2; r >= 0; r--) {
            if(nums[r] <= nums[r+1]){
               rightDp[r] = rightDp[r+1]  + 1; 
            }
        }
        vector<int> ans;
        for(int i =k; i < n-k; i++) {
            if(min(leftDp[i-1],rightDp[i+1]) >= k-1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};