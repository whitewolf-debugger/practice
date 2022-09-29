class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        if (numCourses == 0) {
            return {};
        }
        queue<int> zeroInDegree;
        vector<int> ans;
        for(auto & prerequisite : prerequisites) {
            indegree[prerequisite[0]]++;
        }
        for(int i =0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                
                zeroInDegree.push(i);
            }
        }
        if (zeroInDegree.empty()) {
            return {};
        }
        while(!zeroInDegree.empty()) {
            int currNode = zeroInDegree.front();
            zeroInDegree.pop();
            ans.push_back(currNode);
            for(auto & prerequisite : prerequisites) {
                if(prerequisite[1] == currNode) {
                    indegree[prerequisite[0]]--;
                    if(indegree[prerequisite[0]] == 0) {
                        zeroInDegree.push(prerequisite[0]);
                    }
                }
            }
        }
        for (int in : indegree) {
            if (in != 0) {
                return {};
            }
        }
        return ans;
    }
};