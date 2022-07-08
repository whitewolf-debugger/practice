class Solution {
public:
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target,int start,int prev_color,vector<vector<vector<int>>> &memo){
        //when we are at the end of the array and we have made total target neighbours 
        if(start==m && target ==0) return 0;
        //if we are at the end and the number of neighbours are more then we return INT_MAX
        if(start==m || target<0 ) return INT_MAX;
        //memoisation . It may happen that the target or revious colour is -1 so it will give address error so we have added 2 more conditions 
        if(prev_color != -1 && target != -1 && memo[start][prev_color][target]!=-1){
            return memo[start][prev_color][target];
        }
        int mincost =INT_MAX;
        //if house at current index is painted 
        if(houses[start]!=0){
            //initialize the current cost to 0 at first 
            int currcost = 0;
            //check if previous colur and current colour are same 
            if(prev_color == houses[start]){
                //if previous and current colour are same means they are not neighbours so we donot decrease the target 
                currcost=dfs(houses,cost,m,n,target,start+1,houses[start],memo);
            }
            else{
                //if previous and current colour are not same means prevous house was of different colour then we reduce target increase index
                currcost=dfs(houses,cost,m,n,target-1,start+1,houses[start],memo);
            }
            //min cost will be minimum of current cost and minimum cost since minimum cost has final ans 
            mincost = min(mincost,currcost);
        }
        //if the house was not painted 
        else{
            // try every colour 
            for(int j=0;j<n;j++){
                //stores the current cost 
                int currcost = 0;
                //if current color which we are trying is same as previous coloured house 
                if(prev_color==j+1){
                    //do dfs call do not do any change to target since same color house are not neighbours 
                    currcost=dfs(houses,cost,m,n,target,start+1,j+1,memo);
                }
                //if current color which we are trying is differenct as previous coloured house 
                else{
                    //means previous hour and current house with j+1 colour is will be neighbours so decrease target as there is 1 more neighbour added
                    currcost=dfs(houses,cost,m,n,target-1,start+1,j+1,memo);
                }
                //check if currcost is not INT_MAX when start==m || target<0 means we didnot make the target amount of neighbours 
                if(currcost!=INT_MAX){
                    // mincost stores the minimum cost and if currcost!=INT_MAX so we add the cost of painting current house  i.e cost[start][j]
                    mincost = min(mincost,currcost+cost[start][j]);
                }
            }
        }
        if(prev_color != -1 && target != -1){
            memo[start][prev_color][target] = mincost;
        }
        return  mincost;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> memo(m+3,vector<vector<int>>(n+3,vector<int>(m+3,-1)));
        int min_cost = dfs(houses,cost,m,n,target,0,-1,memo);
        //if min cost is INTMAX means we cannot achive the target so we return -1 else we return min_cost
        return min_cost == INT_MAX ? -1 : min_cost;
    }
};