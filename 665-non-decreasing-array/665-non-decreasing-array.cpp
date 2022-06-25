class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool changed  = false; 
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1]){
                continue;
            }
            if(changed) return false;
            if(i==0 || nums[i+1]>=nums[i-1]){
                nums[i] = nums[i+1];
                changed = true;
            }
            else{
                nums[i+1] = nums[i];
                changed = true;
            }
            
        }
        return true;
    }
};
/*
  3    4    2
  i-1  i    i+1
  at index i nums[i]> nums[i+1]
  so we check for element i-1 and i+1
  element at i+1 is less than element at 3 so if we decrese 4 to 2 it will be error since 
  3  2  2  (3 is greater than 2 ) but we can change 2 to 4 so we do nums[i+1] = nums[i]
  if the other wold have happend  that element at i+1 was bigger than element at i-1 then we 
  would have nums[i] = nums[i+1] to maintain increasing order and since only one change is allowed 
  we are using changed to keep a track 
*/