class Solution {
public:
    //using sliding window approach we solve this question 
    long long zeroFilledSubarray(vector<int>& nums) {
        //intially windowStart is at 0 
        int windowStart = 0;
        int n = nums.size();
        long long ans = 0;
        //keep track of nonzero numbers encountered
        int nonZeroCount = 0;
        for(int windowEnd = 0; windowEnd < n; windowEnd++) {
            if(nums[windowEnd] != 0) {
                nonZeroCount++;
            }
            while(nonZeroCount > 0 && windowStart <= windowEnd) {
                if(nums[windowStart] != 0) {
                    nonZeroCount--;
                }
                windowStart++;
            }
            ans += (windowEnd - windowStart) + 1;
        }
        return ans;
    }
};