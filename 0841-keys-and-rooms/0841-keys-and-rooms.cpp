class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //create a vector visited to keep track of visited node
        vector<int> visited(rooms.size(),false);
        //make a queue to do dfs
        queue<int> pendingrooms;
        int count =0;
        pendingrooms.push(0);
        //mark 0th index as true since whave visited it 
        visited[0] = true;
        while(!pendingrooms.empty()){
            //increase count as we visite very room
            int front = pendingrooms.front();
            count++;
            pendingrooms.pop();
            //take every keey from the room and push it in the queue if it has not been visited 
            for(auto & key : rooms[front]){
                if(!visited[key]){
                    pendingrooms.push(key);
                    //mark that room as visited 
                    visited[key]=true;
                }
            }
        }
        //if count = size of the room return true else return false
        if(count == rooms.size()) return true;
        else return false;
    }
};