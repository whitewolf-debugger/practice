class Solution {
    //taking the mod 
    long long  MOD = 1e9 + 7;

    //dijkstra algo with DP ways which stores the number of shortest paths 
    void dijkstra(vector<vector<pair<long long  , long long >>> &graph, long long  source , long long  n, vector<long long > &weight, vector<long long > &ways) {
        //we take min priority queue since we want the minimum weight/ time node at first and find the path
        priority_queue<pair<long long  , long long >, vector<pair<long long  , long long >> , greater<pair<long long , long long >> > pq;
        //set the number of ways to reach source which was intially 0 as 1 
        ways[source] = 1;

        //push  the intitial weight/ time and the source into the priority queue 
        pq.push({0 , source});
        //set the weight of the source as 0
        weight[source] = 0;

        //while the priority queue isnt empty
        while(!pq.empty()) {

            //take the pair at the top of the priority queue 
            pair<long long  , long long > currPair = pq.top();
            long long  currWeight = currPair.first;
            long long  currNode = currPair.second;
            pq.pop();
            
            //if the current time is more than the previous time to reach the node then we donot do anything 
            if(currWeight  >  weight[currNode]) {
                continue;
            }

            //we travel to the neighbours and update the time to reach them
            for(auto nbr: graph[currNode]) {
                long long  edgeWeight = nbr.first;
                long long  nbrNode = nbr.second;
                //if the previous time to reach them from source was more than current time + edge weight then we update the time to reach
                if(weight[nbrNode] > currWeight + edgeWeight) {
                    weight[nbrNode] = currWeight + edgeWeight;
                    //push the updated node and the new current time i.e currWeight + edgeWeight to the priority queue 
                    pq.push({weight[nbrNode] , nbrNode});
                    //update the  number of ways you can arrive at the neighbour node to what we have discovered for parent
                    ways[nbrNode] = ways[currNode];
                } else if(weight[nbrNode] == currWeight + edgeWeight) {
                    //if we have 2 path with same weight then update the number of ways since it can over flow we % it with MOD 
                    ways[nbrNode] = (ways[currNode] + ways[nbrNode])%MOD;
                }
            }

        }
    }

public:

    long long  countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long , long long >>> graph(n);

        //creating adjacency matrix for the given edges
        for(auto & edge : roads) {
            long long  source = edge[0];
            long long  destination = edge[1];
            long long  weight = edge[2];
            graph[source].push_back({weight, destination});
            graph[destination].push_back({weight , source});
        }

        //time helps to calculate the shortest path
        vector<long long > time(n, LONG_MAX);

        //ways help to calculate  number of ways you can arrive at your destination in the shortest amount of time.
        vector<long long > ways(n);
        dijkstra(graph, 0, n ,time,ways);
        //ans of number of ways you can arrive at n-1 lies at ways n-1
        return ways[n-1];
    }
};

/*
We use Dijkstra algorithm to find the Shortest Path from src = 0 to dst = n - 1.
While dijkstra, we create additional ways array, where ways[i] keeps the number of shortest path from src = 0 to dst = i. Then the answer is ways[n-1].




*/