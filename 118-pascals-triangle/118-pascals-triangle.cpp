class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;
        if (n==0) return ans;
        if(n==1){
            ans.push_back({1});
            return ans;
        }
        if(n==2){
            ans.push_back({1});
            ans.push_back({1,1});
            return ans;
        }
        ans.push_back({1});
        ans.push_back({1,1});
        int level =2;
        for(int i=1;i<n-1;i++){
            vector<int> v;
            for(int j=0;j<=level;j++){
                if(j==0){
                    v.push_back(1);
                }
                else if(j == level){
                        v.push_back(1);
                }
                else{
                    v.push_back(ans[i][j]+ans[i][j-1]);
                }
            }
            ++level;
            ans.push_back(v);
            
        }
        return ans;
    }
};