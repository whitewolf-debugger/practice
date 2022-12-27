class Solution {
public:
    //calculates the distance between the biker and the worker
    int calDist(vector<int> &worker , vector<int> &bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }

            
    void dp(vector<vector<int>> &workers, vector<vector<int>> & bikes, int worker, int m, int n,vector<bool>& taken,int currDistSum, int &ans) {
        //base case we store the least ans after alloting bike to workers
        if(worker >= n) {
            ans =min (ans ,  currDistSum);
            return;
        }
        //if at any stage the previous ans is less the ans which we are currently calculating 
        //there calculating further will be useless 
        if(ans <= currDistSum) {
            return;
        }
        
        //backtracking we start assigning  different bike to worker 0 and worker + 1 and so on every time 
        for(int i =0; i < m; i++) {
            if(!taken[i]) {
                //important backtracking step
                taken[i] = true;
                dp(workers, bikes, worker + 1, m, n, taken,currDistSum + calDist(workers[worker], bikes[i]),ans);
                taken[i] = false;
            }
        }
    }

    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int ans = INT_MAX;
        int n = workers.size();
        int m  = bikes.size();
        vector<bool> taken(m, false);        
        dp(workers , bikes, 0, m, n,taken,0,ans);
        return ans;
    }
};