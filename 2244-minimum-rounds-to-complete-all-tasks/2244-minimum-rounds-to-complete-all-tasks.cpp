class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n =tasks.size();
        //pair : {first , second}
        //taking min priority queue of pairs i.e pair with first element in the pair as minimum element we be at the top
        priority_queue<pair<int , int>  , vector<pair<int , int> >, greater<pair<int ,int>>> pq;
        unordered_map<int ,int > mp;
        //map the difficulty and the  tasks 
        for(auto & difficulty : tasks) {
            mp[difficulty]++;
        }

        //push the frequency of the task and the difficulty in the min priority queue
        for(auto & freq: mp) {
            pq.push({freq.second , freq.first});
        }
        //ans sores the ans 
        int ans = 0;
        while(!pq.empty()) {
            //get the top of the priority_queue 
            int freq = pq.top().first;
            int element = pq.top().second;
            pq.pop();

            //if frequency of a task becomes 1 then we return -1 we want frequency to be 0;
            if(freq == 1) {
                return -1;
            }else if(freq % 3 == 0) {
                //if the (frequency of the task) % 3 =0 means it can be divided into tasks of size 3 so we subrtact 3 from frequency
                ans++;
                //increase the ans(min number of rounds to complete task)
                freq -= 3;
            } else if(freq % 2 == 0) {
                //we come here since  (frequency of the task) % 3 != 0
                //if the (frequency of the task) % 2 =0 means it can be divided into tasks of size 2 so we subrtact 2 from frequency
                ans ++;
                freq -= 2;
            } else {
                //else if (frequency of the task) % 3 != 0 and (frequency of the task) % 2 != 0 example  5 frequency
                ans +=1;
                //so we subtract 3 tasks from it 
                freq -= 3;
            }
            //after all the subtraction if frequency is  > 0 then we push that in the priority queue 
            if(freq > 0) {
                pq.push({freq, element});
            }
        }

        //return ans 
        return ans;
    }
};