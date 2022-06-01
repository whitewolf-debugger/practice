class Solution {
public:
    void helper(vector<int>& nums,vector<int> &rs,int sum,int index){
        if(index >= nums.size()){
            return;
        }
        sum+=nums[index];
        helper(nums,rs,sum,index+1);
        rs[index]=sum;
    }
    vector<int> runningSum(vector<int>& nums) {
        vector<int> rs(nums.size());
        int sum=0;
        helper(nums,rs,sum,0);
        return rs;
    }
};