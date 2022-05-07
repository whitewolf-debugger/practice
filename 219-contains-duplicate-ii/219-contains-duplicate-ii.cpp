class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        //creating map of nums[i]:{indexes}
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto x:mp){
            // if element appears less than once then continue
            if(x.second.size()<2) continue;
            // when element appears more than once
            vector<int> v = x.second;
            for(int i=0;i<v.size();i++){
                for(int j=i+1;j<v.size();j++){
                    //calculating difference if <= k
                    if(abs(v[j]-v[i])<=k){
                        return true;
                    }
                }
            }
        }
        //when we come out of the for loops means ans is false since we didnot return true
        return false;
    }
};
/*
    0 1 2 3
    1 2 3 1
    k =3
    1:{0,3};
       i j
       abs(v[j]-v[i]) = 3
    2:{1};
    3:{2};



*/