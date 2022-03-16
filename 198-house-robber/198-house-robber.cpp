class Solution {
public:
    int rob_help(vector<int> &nums,int n,int *output){
        int ans;
        if(n==0){
            ans = nums[n];
        }
        if(n<0){
            return 0;
        }
        if(output[n]!=-1){
            return output[n];
        }
        else{
            int op1 = nums[n] + rob_help(nums,n-2,output);
            int op2 = rob_help(nums,n-1,output);
            ans = max(op1,op2);
        }
        output[n]=ans;
        return output[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        int *output = new int[n+1]; 
        for(int i=0;i<=n;i++){
            output[i]=-1;
        }
        return rob_help(nums,n,output);
    }
};