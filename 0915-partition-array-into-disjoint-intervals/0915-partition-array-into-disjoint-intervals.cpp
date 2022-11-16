class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int,int>> left;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> right;
        for(int i =0 ; i < n;i++) {
            right.push({nums[i] , i});
        }
        
        for(int i = 0 ; i < n; i++) {
            left.push({nums[i],i});
            while(!right.empty() && right.top().second <= i) {
                right.pop();
            }
            if(left.top().first <= right.top().first) {
                return i+1;
            }
        }
        return -1;
    }
};
/*

 
 


*/