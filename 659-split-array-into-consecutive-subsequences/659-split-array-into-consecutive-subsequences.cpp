class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        //stires the frequency of each element
        unordered_map<int ,int> freqMap;
        //stores the frequency of next needed element
        unordered_map<int ,int> need;
        int n = nums.size();
        
        //making map of elements
        for(int i =0; i < n; i++){
            freqMap[nums[i]]++;
        }
        
        //traversing in the nums array
        for(int &num: nums){
            //if elements frequency is 0 then we do not do naything
            if(freqMap[num] == 0) continue;
            
            //if there is need of current element full fill it and do need[num]-- and increase need for next element need[num+1]++
            else if(need[num] > 0){
                need[num]--;
                freqMap[num]--;
                need[num+1]++;
                
            }else if(freqMap[num] >0 && freqMap[num+1] >0 && freqMap[num+2] >0 ){
                //take next 3 element hypthetically and increase need for next element i.e num+3
                freqMap[num]--;
                freqMap[num+1]--;
                freqMap[num+2]--;
                need[num+3]++;
                
            } else{
                //if all these are not possible return false;
                return false;
            }
        }
        return true;
    }
};

/* 
    for each num in nums first try placing it in one of the existing subseq.
    if no subseq. needs that number.
    then, try creating a new subseq. of atleast length 3 starting with that num.

    if neither of the two condtn is true, we return false
    since, that num can't be a part of any subseq.


*/