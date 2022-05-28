class Solution {
public:
    // void find(vector<int>& nums,int low,int high,unordered_set<int> seen,int &ans){
    //     if(low>high){
    //         return;
    //     }
    //     if(seen.find(low)==seen.end()){
    //         ans = low;
    //         return;
    //     }
    //     find(nums,low+1,high,seen,ans);
    // }
    int missingNumber(vector<int>& nums) {
        int low =0;
        int high  = nums.size();
        unordered_set<int> seen;
        for(int i = 0 ; i < nums.size();i++){
            seen.insert(nums[i]);
        }
        int ans;
        for(int i= low ;i <= high;i++){
            if(seen.find(i)==seen.end()) ans = i;
        }
        return ans ;
    }
};