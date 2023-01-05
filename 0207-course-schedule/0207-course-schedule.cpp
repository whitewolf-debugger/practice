class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //make the adjacency vector
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        // if x -> y means we have to do x before y so increase indegree of edge[1]
        for(auto& edge: prerequisites) {
            indegree[edge[1]]++;
            //push the node y in inside the nbr of x so that after decreasing indree of nbr if it becomes 0 we can take nbr in queue
            adj[edge[0]].push_back(edge[1]);
        }
        queue<int> pendingNodes;
        //push the node with indegree 0 into the queue 
        for(int i= 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                pendingNodes.push(i);
            }
        }
        //count states the course which we have done 
        int count = 0;

        
        while(!pendingNodes.empty()) {
            //remove the current node means do the current course 
            int top = pendingNodes.front();
            pendingNodes.pop();
            //increase the number of course we have done 
            count++;
            //now decrease 1 requirement for nbr node . if indree of nbr is 0 means we can do that course so we do that course 
            for(auto &nbr: adj[top]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    //push the doable course int the queue 
                    pendingNodes.push(nbr);
                }
            }
        }

        //at the end if the count is equal to number of course that means we can do all the courses 
        return count == numCourses;
    }
};