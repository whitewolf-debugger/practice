class Solution {
public:
    //recursive approach 
    void helper(vector<int>& nums,vector<int> &rs,int sum,int index){
        //base case if the index exceeds the size of array return
        if(index >= nums.size()){
            return;
        }
        //else add element of nums tu sum
        sum+=nums[index];
        //place sum at that index in rs
        rs[index]=sum;
        //move forward
        helper(nums,rs,sum,index+1);
    }
    vector<int> runningSum(vector<int>& nums) {
        vector<int> rs(nums.size());
        int sum=0;
        helper(nums,rs,sum,0);
        return rs;
    }
};