class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         vector<int>index;
        unordered_map<int,int> mp;
        // map all the elements with index+1
        for(int i=0;i<numbers.size();i++){
            mp[numbers[i]]=i+1;
        }
        int diff;
        for(int i=0;i<numbers.size();i++){
            diff = target - numbers[i];
            //if index of difference != 0 means elementis there 
            if(mp[diff]!=0){
                //push the i+1 index in index
                index.push_back(i+1);
                //push index of difference in the index 
                index.push_back(mp[diff]);
                //breakout
                break;
            }
        }
        //return ans
        return index;
    }
};