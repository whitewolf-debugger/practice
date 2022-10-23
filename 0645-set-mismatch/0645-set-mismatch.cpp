class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int n = nums.size();
        vector<int> freqMap(n+1,0);
        for(int i =0; i < n;i++) {
            freqMap[nums[i]]++;
        }
        for(int i = 1; i <= n;i++) {
            if(freqMap[i] > 1) {
                ans[0] = i;
            }
            if(freqMap[i] == 0) ans[1] = i;
        }
        return ans;
    }
};