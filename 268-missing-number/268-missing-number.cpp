class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // sum of number till n number till n
        int sum = (n*(n+1))/2;
        for(auto x:nums){
           sum=sum-x;
        }
        //sum has the missing number 
        return sum;
    }
};