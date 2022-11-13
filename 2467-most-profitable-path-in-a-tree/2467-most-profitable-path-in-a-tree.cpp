class Solution {
public:
    //calculates the maximum profit path for alice 
    int calProfit(vector<vector<int>>& adj,int startVertex,int parent,vector<int> &amount) {
        //get the current profit irrespective of whether positive or negetive we need to add it to check for max profit path
        int currProfit = amount[startVertex];
        int ans = INT_MIN;
        //do dfs and ans is the maximum profit after doing dfs 
        for(auto &nbr : adj[startVertex]) {
            //if the neighbour is the current node itself or the parent node then we skip rest since it will create self loop
            if(nbr == startVertex || nbr == parent) continue;
            ans = max(ans , calProfit(adj,nbr,startVertex,amount));
        }
        // base case if ans is INT_MIN means we have reached the leaf node then we return the profit amount at that node 
        if(ans == INT_MIN) return currProfit;
        //else we add the current profit to the ans and return it 
        else return currProfit + ans;
    }
    //do dfs and update parent of everynode along with distance 
    void dfs(int startVertex , int p, int d ,vector<vector<int>> &adj,vector<int> &distance , vector<int> &parent) {
        distance[startVertex] = min(distance[startVertex] ,d);
        parent[startVertex] = p;
        for(auto &nbr : adj[startVertex]) {
            //check for valid neighbour to avoid self loop 
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
        //set the distance to max for every node since we want minimum distance for every node for alice in distance vector
        vector<int> distance(n,INT_MAX);
        //parent stores the parent so that we can track path to 0 for bob 
        vector<int> parent(n);
        dfs(0,0,0,adj,distance,parent);
        //initialdistance of bob is 0 ofc he is at his starting place 
        int bobDistance = 0;
        //set the current bobpostion to bob 
        int currBobPosition = bob;
        //we search untill currBobPosition is not 0 means bob has not reached 0 
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
        //ans stores the ans 
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