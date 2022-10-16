class Solution {
public:
    int minDiff(int i,vector<int> & jobDifficulty,int days,vector<vector<int>> &memo){
        //memoization
        if(memo[i][days] != -1) return memo[i][days];
        //if the number of days left is 1 so we take the max difficulty for the day and return that
        if(days == 1) {
            int res = 0;
            for(int j = i; j < jobDifficulty.size();j++) {
                res = max(res,jobDifficulty[j]);
            }
            return res;
        }
        int res = INT_MAX;
        int dailyMaxJobDiff = 0;
        //take the job form i to jobDifficulty.size() - days + 1 since rest days should have some work and move to next day
        for(int j = i; j < jobDifficulty.size() - days + 1;j++) {
            dailyMaxJobDiff = max(dailyMaxJobDiff,jobDifficulty[j]); 
            //add the max difficulty for that day from i to jobDifficulty.size() - days + 1 to the next days result 
            res = min(res,dailyMaxJobDiff +minDiff(j+1,jobDifficulty,days-1,memo));
        }
        return memo[i][days] = res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        //base case if w
        if(n < d){
            return -1;
        }
        vector<vector<int>> memo(301,vector<int>(11,-1));
        return minDiff(0,jobDifficulty,d,memo);
    }
};


/*

The dynamic programming solution to this problem consists of three components:

State definition:

Index i (the index of the first task for today in the jobDifficulty array) and day d (number of remaining days) will define the DP state. min_diff(i, d) refers to the minimum difficulty when starting at the ithi^{th}i 
th
  job with d days left.

min_diff(0, d) will be the final answer since it represents starting at the beginning of the job array and finishing all jobs in exactly d days.

State transition function:

The job at index j will be the first task for the upcoming day, therefore, the jobs to be finished today are all jobs with indices between i and j, which is jobDifficulty[i:j]. Since the difficulty of a day is the maximum difficulty of a job done in that day, the maximum of jobDifficulty[i:j] will be added to the sum of job difficulties.

With this in mind, let's formulate the state transition function as follows:

min_diff(i, d) = min_diff(j, d - 1) + max(jobDifficulty[i:j]) for all j > i

Base case:

When there is only 1 day remaining, we need to finish all unfinished jobs on that day and increase the difficulty of the job schedule by the maximum difficulty of these jobs.

Before we dive into the code, let's take a moment to consider edge cases and optimizations.

One edge case that we must consider is if the number of days is more than the number of tasks, then we won't be able to arrange at least one job per day; in this case, we should return -1.

class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {

        int n = jobDifficulty.length;
        // Edge case: make sure there is at least one job per day
        if (n < d) {
            return -1;
        }

        int[][] mem = new int[n][d + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= d; j++) {
                mem[i][j] = -1;
            }
        }

        return minDiff(0, d, jobDifficulty, mem);
    }

    private int minDiff(int i, int daysRemaining, int[] jobDifficulty, int[][] mem) {
        // Use memoization to avoid repeated computation of states
        if (mem[i][daysRemaining] != -1) {
            return mem[i][daysRemaining];
        }

        // Base case: finish all remaining jobs in the last day
        if (daysRemaining == 1) {
            int res = 0;
            for (int j = i; j < jobDifficulty.length; j++) {
                res = Math.max(res, jobDifficulty[j]);
            }
            return res;
        }

        int res = Integer.MAX_VALUE;
        int dailyMaxJobDiff = 0;
        // Iterate through possible starting index for the next day
        // and ensure we have at least one job for each remaining day.
        for (int j = i; j < jobDifficulty.length - daysRemaining + 1; j++) {
            dailyMaxJobDiff = Math.max(dailyMaxJobDiff, jobDifficulty[j]);
            res = Math.min(res, dailyMaxJobDiff + minDiff(j + 1, daysRemaining - 1, jobDifficulty, mem));
        }
        mem[i][daysRemaining] = res;
        return res;
    }
}

*/