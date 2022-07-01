class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(),false);
        queue<int> pendingrooms;
        int count =0;
        pendingrooms.push(0);
        visited[0] = true;
        while(!pendingrooms.empty()){
            int front = pendingrooms.front();
            count++;
            pendingrooms.pop();
            for(auto & key : rooms[front]){
                if(!visited[key]){
                    pendingrooms.push(key);
                    visited[key]=true;
                }
            }
        }
        if(count == rooms.size()) return true;
        else return false;
    }
};