class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int top =0;
        int left =0;
        int bot = n-1;
        int right = n-1;
        int dir =0;
        int num = 1;
        while(top<=bot && left<=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    ans[top][i]=num;
                    num++;
                }
                dir++;
                top++;
            }
            else if(dir==1){
                for(int r = top; r<=bot;r++){
                    ans[r][right] = num;
                    num++;
                }
                dir++;
                right--;
            } 
            else if(dir==2){
                for(int c = right;c>=left;c--){
                    ans[bot][c] = num;
                    num++;
                }
            dir++;
            bot--;
            }
            else if(dir==3){
                for(int c = bot; c>=top;c--){
                    ans[c][left]= num;  
                    num++;
                }
                left++;
                dir=0;
            }
        }
        return ans;
    }
};