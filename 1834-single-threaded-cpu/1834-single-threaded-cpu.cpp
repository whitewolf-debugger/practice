class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        //used to decide what task we are supposed to do 
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>> > nextTask;
        
        //we will sort the task according to the start time and push valid task in the nextTask 
        vector<vector<int>> sortedTask;
        
        //make the vector sorted task by puhing the enqueueTime , processingTime and the index
        for(int i =0; i < tasks.size(); i++) {
            sortedTask.push_back({tasks[i][0], tasks[i][1], i});
        }


        //osrt the tasks 
        sort(sortedTask.begin(),sortedTask.end());
        vector<int> ans;
        
        long long currentTime = 0;
        int taskIndex = 0;
        
        //while the priority_queue is not empty and we have not reached the end of the task array
        while(taskIndex < tasks.size() || !nextTask.empty()) {
            //if the priority queue is empty and the current time is less than the enqueue time of the current task
            if(nextTask.empty() && currentTime < sortedTask[taskIndex][0]) {
                //the cpu will sit idle till the time sortedTask[taskIndex][0] so we skip to that time 
                currentTime = sortedTask[taskIndex][0];
            }
            
            //while taskIndex is sorted task size and the 
            while(taskIndex < sortedTask.size() && currentTime >= sortedTask[taskIndex][0]) {
                //push the end time of whose enqueue time is less than the current time into the priority queue
                nextTask.push({sortedTask[taskIndex][1] , sortedTask[taskIndex][2]});
                //increase the index of current task
                ++taskIndex;
            }
            
            //remove the top of nextTask as it is the task with least time required to finish
            auto[processTime , index] = nextTask.top();
            nextTask.pop();
            
            //update the current time 
            currentTime += processTime;
            //push the index of recently done task in the ans
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