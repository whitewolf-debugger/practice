class Solution {
public:
    int climbstairs(int n,int *output){
        int ans;
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(output[n]!=-1){
            return output[n];
        }
        int op1 = climbstairs(n-1,output); 
        int op2 = climbstairs(n-2,output);
        ans = op1+op2;
        output[n]=ans;
        return output[n];
    }
    int climbStairs(int n) {
        int *output = new int[n+1];
        for(int i=0;i<=n;i++){
            output[i]=-1;
        }
        return climbstairs(n,output);
    }
};