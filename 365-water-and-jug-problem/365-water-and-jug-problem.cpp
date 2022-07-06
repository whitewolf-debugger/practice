class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        //base case if water in both the jug are less than target return false
        if(jug1Capacity+jug2Capacity<targetCapacity){
            return false;
        }
        unordered_map<int,bool> visited;
        // all the volume changes which we can do add or remove 
        vector<int> volume ={+jug1Capacity,+jug2Capacity,-jug1Capacity,-jug2Capacity};
        visited[0]=true;
        queue<int> pendingNodes;
        pendingNodes.push(0);
        while(!pendingNodes.empty()){
            //get the current node 
            int current = pendingNodes.front();
            pendingNodes.pop();
            //if we hit the targer return true
            if(current==targetCapacity) 
                return true;
            for(auto vol:volume){
                int newvol=current+vol;
                //check all the possiblilites once increasing then decreasing for all the bottles 
                if(newvol>=0 && newvol<=(jug1Capacity+jug2Capacity) && !visited[newvol]){
                    visited[newvol]=true;
                    //insert new volume in queue
                    pendingNodes.push(newvol);
                }
            }
        }
        //we are here means we were not able to make till the target 
        return false;
    }
};