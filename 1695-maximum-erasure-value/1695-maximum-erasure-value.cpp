class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int sum =0;
        int ans = 0;
        int start=0;
        int i = 0;
        while(i<nums.size()){
            int curr  =  nums[i];
            if(seen.find(curr)==seen.end()){
                seen.insert(curr);
                sum+=curr;
                ans = max(ans,sum);
                i++;
            }
            else{
                int del = nums[start];
                seen.erase(del);
                sum=sum - del;
                start++;
            }
        }
        return ans;
    }
};