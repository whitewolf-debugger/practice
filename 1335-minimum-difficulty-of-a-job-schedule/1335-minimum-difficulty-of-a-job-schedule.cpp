class Solution {
public:
    int minDiff(int i,vector<int> & jobDifficulty,int days,vector<vector<int>> &memo){
        if(memo[i][days] != -1) return memo[i][days];
        if(days == 1) {
            int res = 0;
            for(int j = i; j < jobDifficulty.size();j++) {
                res = max(res,jobDifficulty[j]);
            }
            return res;
        }
        int res = INT_MAX;
        int dailyMaxJobDiff = 0;
        for(int j = i; j < jobDifficulty.size() - days + 1;j++) {
            dailyMaxJobDiff = max(dailyMaxJobDiff,jobDifficulty[j]);
            res = min(res,dailyMaxJobDiff +minDiff(j+1,jobDifficulty,days-1,memo));
        }
        return memo[i][days] = res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if(n < d){
            return -1;
        }
        vector<vector<int>> memo(301,vector<int>(11,-1));
        return minDiff(0,jobDifficulty,d,memo);
    }
};