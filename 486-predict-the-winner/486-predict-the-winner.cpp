class Solution {
public:
    int sum(vector<int>& nums,int endIndex,int startIndex){
        if(startIndex>endIndex) return 0;
        int op1 = nums[endIndex]+min(sum(nums,endIndex-2,startIndex),sum(nums,endIndex-1,startIndex+1));
        int op2 = nums[startIndex]+min(sum(nums,endIndex,startIndex+2),sum(nums,endIndex-1,startIndex+1));       
        return max(op1,op2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int s=0;
        int Asum = sum(nums,n-1,0);
        for(int i=0;i<nums.size();i++){
            s+= nums[i];
        }
        if(Asum>=(s-Asum)){
            return true;
        }
        return false;
    }
};