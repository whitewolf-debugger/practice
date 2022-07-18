class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int row = 0;row<m;row++){
            for(int col=1;col<n;col++){
                matrix[row][col]+=matrix[row][col-1];
            }
        }
        int count =0;
        for(int col1 = 0;col1<n;col1++){
            for(int col2=col1;col2<n;col2++){
                unordered_map<int,int> mp;
                mp[0]=1;
                int sum =0;
                for(int row =0;row<m;row++){
                    sum+=matrix[row][col2]-(col1>0?matrix[row][col1-1]:0);
                    count+=mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return count;
    }
};
/*

  





*/