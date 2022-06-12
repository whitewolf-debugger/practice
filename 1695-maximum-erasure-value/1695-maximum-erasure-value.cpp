class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int sum =0;
        int ans = 0;
        int start=0;
        int i = 0;
        while(i<nums.size()){
            int curr  =  nums[i];
            // if current element is not in seen
            if(seen.find(curr)==seen.end()){
                seen.insert(curr);
                //add to current 
                sum+=curr;
                //update max
                ans = max(ans,sum);
                i++;
            }//incase found
            else{
                //remove the dublicate to make different  sequence 
                int del = nums[start];
                seen.erase(del);
                sum=sum - del;
                //increse start index once 1st element was found 
                start++;
            }
        }
        //return ans 
        return ans;
    }
};