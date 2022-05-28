class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int low =0;
        int high  = nums.size();
        unordered_set<int> seen;
        for(int i = 0 ; i < nums.size();i++){
            seen.insert(nums[i]);
        }
        //int ans;
        for(int i= low ;i <= high;i++){
            if(seen.find(i)==seen.end()) return  i;
        }
        return 0 ;
    }
};