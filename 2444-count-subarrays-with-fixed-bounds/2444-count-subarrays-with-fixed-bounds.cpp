class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int badNumberIndex = -1;
        int latestMinIndex = -1;
        int latestMaxIndex = -1;
        long long ans = 0;
        for(int i = 0 ; i < n ;i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                latestMinIndex = -1;
                latestMaxIndex = -1;
                badNumberIndex = i;
            }
            
            if(nums[i] == minK) {
                latestMinIndex = i;
            } 
            if(nums[i] == maxK) {
                latestMaxIndex = i;
            }

            ans += max(0,min(latestMinIndex, latestMaxIndex) - badNumberIndex);
        }

        return ans;
    }
};
/*

Explanation : 
    nums {

    [_,_,_,_,_,_]
     i

    }
    ans stores the result
    if nums[i] == minK
    store the latest minimum number index
    if nums[i] == maxK 
    store the latest maximum number index 
    if nums[i] < minK || nums[i] > maxK
    it is a bad number and cannot be included in subarray
    store the index in badNumberIndex
    the number of subarrays we can make starts from index 
    ans += max(0,min(latestMinIndex, latestMaxIndex) - badNumberIndex);
    i.e the subarrayincluding minK and maxK + including each element between
    min(latestMinIndex, latestMaxIndex)  and badNumberIndex one by one 
    
    [_,_,_,_,_,_,_,_]
     b   
           m   n
           we are at n currently so at n
           m -> maxK
           n  -> minK
           
           ans includes subarrays
                        { _,_,_
                          m   n 
                        
                         _,_,_,_
                           m   n
                           
                         _,_,_,_,_
                             m   n
                        }
                           
                         
        

*/