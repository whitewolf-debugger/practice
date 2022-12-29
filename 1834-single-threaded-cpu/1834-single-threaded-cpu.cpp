class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>> > nextTask;
        
        vector<vector<int>> sortedTask;
        
        for(int i =0; i < tasks.size(); i++) {
            sortedTask.push_back({tasks[i][0], tasks[i][1], i});
        }
        
        sort(sortedTask.begin(),sortedTask.end());
        vector<int> ans;
        
        long long currentTime = 0;
        int taskIndex = 0;
        
        while(taskIndex < tasks.size() || !nextTask.empty()) {
            if(nextTask.empty() && currentTime < sortedTask[taskIndex][0]) {
                currentTime = sortedTask[taskIndex][0];
            }
            
            while(taskIndex < sortedTask.size() && currentTime >= sortedTask[taskIndex][0]) {
                nextTask.push({sortedTask[taskIndex][1] , sortedTask[taskIndex][2]});
                ++taskIndex;
            }
            
            auto[processTime , index] = nextTask.top();
            nextTask.pop();
            
            currentTime += processTime;
            ans.push_back(index);
        }
        
        
        return ans;
    }
};
/*
1. If the CPU is idle and there are no available tasks to process, the CPU remains idle.
2. If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
3.



*/