class Solution {
public:
    int calProfit(vector<vector<int>>& adj,int startVertex,int parent,vector<int> &amount) {
        int currProfit = amount[startVertex];
        int ans = INT_MIN;
        for(auto &nbr : adj[startVertex]) {
            if(nbr == startVertex || nbr == parent) continue;
            ans = max(ans , calProfit(adj,nbr,startVertex,amount));
        }
        if(ans == INT_MIN) return currProfit;
        else return currProfit + ans;
    }
    void dfs(int startVertex , int p, int d ,vector<vector<int>> &adj,vector<int> &distance , vector<int> &parent) {
        distance[startVertex] = min(distance[startVertex] ,d);
        parent[startVertex] = p;
        for(auto &nbr : adj[startVertex]) {
            if(nbr == startVertex || nbr == p) continue;
            dfs(nbr,startVertex,d+1,adj,distance,parent);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n);
        //create the adjacency list 
        for(auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> distance(n,INT_MAX);
        vector<int> parent(n);
        dfs(0,0,0,adj,distance,parent);
        int bobDistance = 0;
        int currBobPosition = bob;
        while(currBobPosition != 0) {
            //if the distance of node from alice is more than the distance from bob and it is in path to 0 then bob will definately cover it 
            if(bobDistance < distance[currBobPosition]) {
                //so we make the amount of profit which alice can make from this node to 0 
                amount[currBobPosition] = 0;
            }
            //if the distance of node from alice and bob are same and in path of bob from his node to 0 then they both can cover this node 
            else if(bobDistance == distance[currBobPosition]) {
                //so the amount which alice can get from this node if he visits is amount[currBobPosition] /2 
                amount[currBobPosition] = amount[currBobPosition]/2;
            } 
            //update the bobs postion to next position 
            currBobPosition = parent[currBobPosition];
            //increase the distance of bob as we move to the next node 
            bobDistance++;
        }
        vector<bool> visited(n,false);
        int ans = calProfit(adj,0,0,amount);
        return ans;
    }
};
/*

 
 
amount has the amount which has to be added to total 
we calculate distance of every node from 0 doing dfs and we make vector parent to get parent of every node so that we can use that for calculation of bobs distance and updating the amount and also there are multiple paths so we donot use the vector visited(n) of size n to keep track of visited nodes 
distance vector stores the distance of every node from 0 i.e distance of alice from every node 
the path of bob is fixed he moves from his node to 0 so the nodes close to bob will be covered by bob definately  so we make amount  = 0 at that position but the nodes which are equidistant from both of them then we divide the amount / 2 where bobDistance == distance[currBobPosition].
we do another dfs to calcualte the final maximum profit by doing dfs and visiting every node and adding the updated amount after bobs goes to 0

*/