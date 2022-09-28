//Dijkstras Approach 
class Solution {
public:
    void dijkstras(vector<vector<pair<int,int>>> adj,vector<int> &signalReceivedAt,int source,int n) {
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>>> pq;
        //push the source along with its weight in the priority queue 
        pq.push({0,source});
        //we keep the distance of source from source to be 0
        signalReceivedAt[source] = 0;
        //same as BFS approach 
        while(!pq.empty()) {
            //get the current time(sum of all previous weight) and current node 
            int currNodeTime = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();
            //check for the neighbouring edges 
            for(auto & edge : adj[currentNode]) {
                //get the weight of path from current node to  neighbour 
                int time = edge.first;
                int nbr = edge.second;
                //check if that time to reach from source  we had earlier is more than the time we get by adding (current time + this time)
                if(signalReceivedAt[nbr] > time + currNodeTime) {
                    //update the time to reach that node 
                    signalReceivedAt[nbr] = time + currNodeTime;
                    //push the new time and the neighbour in the min heap
                    pq.push({signalReceivedAt[nbr],nbr});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &time : times) {
            int source = time[0];
            int destination = time[1];
            int weight = time[2];
            //make adjacency list having source :{weight,destination}
            adj[source].push_back({weight,destination});
        }
        //stores the time(weight) from source to the nodes
        vector<int> signalReceivedAt(n+1,INT_MAX);
        int ans = INT_MIN;
        dijkstras(adj,signalReceivedAt,k,n);
        for(int i =1; i <= n ;i++) {
            ans = max(ans,signalReceivedAt[i]);
        }
        return ans == INT_MAX ? -1 : ans;
        
    }
};