class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        int count=0;
        for(int i=0;i<nums.size();i++){
            //mp maps elements with all its indices in vector
            mp[nums[i]].push_back(i);
        }
        //x maps element:array of indices 
        for(auto x: mp){
            vector<int> v =x.second;
            int size = v.size();
            // if element is present only once we donot do anything
            if(size<2){
                continue;
            }
            // element is present more than once so we visit every index  and check for i*j and increase count accordingly
            for(int i=0;i<(size-1);i++){
                 for(int j=i+1;j<size;j++){
                     int mul = v[i]*v[j];
                     if(mul%k==0){
                         count+=1;
                     }
                 }
            }
        }
        return count;
    }
};
/*
     0 1 2 3 4 5 6
     3 1 2 2 2 1 3
     k = 2
     unordered_map<int,vector<int>> ind;
     mp[nums[i]]=i;
     
     3:0,6
     1:1,5
     2:2,3,4
     
    
     
 
*/