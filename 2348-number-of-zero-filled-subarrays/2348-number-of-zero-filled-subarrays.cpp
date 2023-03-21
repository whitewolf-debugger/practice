class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int windowStart = 0;
        int n = nums.size();
        long long ans = 0;
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