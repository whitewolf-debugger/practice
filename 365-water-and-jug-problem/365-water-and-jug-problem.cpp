class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(jug1Capacity+jug2Capacity<targetCapacity){
            return false;
        }
        unordered_map<int,bool> visited;
        vector<int> volume ={+jug1Capacity,+jug2Capacity,-jug1Capacity,-jug2Capacity};
        visited[0]=true;
        queue<int> pendingNodes;
        pendingNodes.push(0);
        while(!pendingNodes.empty()){
            int current = pendingNodes.front();
            pendingNodes.pop();
            if(current==targetCapacity) 
                return true;
            for(auto vol:volume){
                int newvol=current+vol;
                if(newvol>=0 && newvol<=(jug1Capacity+jug2Capacity) && !visited[newvol]){
                    visited[newvol]=true;
                    pendingNodes.push(newvol);
                }
            }
        }
        return false;
    }
};