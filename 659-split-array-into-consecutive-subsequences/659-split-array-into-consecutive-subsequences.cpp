class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int ,int> freqMap;
        unordered_map<int ,int> need;
        int n = nums.size();
        
        for(int i =0; i < n; i++){
            freqMap[nums[i]]++;
        }
        
        for(int &num: nums){
            if(freqMap[num] == 0) continue;
            
            else if(need[num] > 0){
                need[num]--;
                freqMap[num]--;
                 need[num+1]++;
                
            } else if(freqMap[num] >0 && freqMap[num+1] >0 && freqMap[num+2] >0 ){
                
                freqMap[num]--;
                freqMap[num+1]--;
                freqMap[num+2]--;
                 need[num+3]++;
                
            } else{
                return false;
            }
        }
        return true;
    }
};
/*

    1,  2,  3,  3,  4,  4,  5,  5
            ^                            
    unordered_map<int , int> mp = {
        1:0
        2:0
        3:1
        4:1
        5:1
    }
    
    
    unordered_map<int,int> um ={
    
        3:1
    }

1. map the frequency
2. check whether frequency of current element is greater than 0
3. if frequency of current element is greater than 0 then check for frequncies of next consecutive elements



*/