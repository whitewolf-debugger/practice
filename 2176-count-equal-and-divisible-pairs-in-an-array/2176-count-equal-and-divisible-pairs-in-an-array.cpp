class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        int count=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto x: mp){
            vector<int> v =x.second;
            int size = v.size();
            if(size<2){
                continue;
            }
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