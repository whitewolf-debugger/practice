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
        // for(int i  = 0 ; i<nums.size();i++){
        //     sum+=nums[i];
        //     rs[i] = sum;
        // }
        helper(nums,rs,sum,0);
        return rs;
    }
};