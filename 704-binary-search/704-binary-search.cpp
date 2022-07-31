class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start =0;
        int end = nums.size()-1;
        while(start<=end){
            int mid1= start+(end-start)/3;
            int mid2 = end-(end-start)/3;
            if(nums[mid1]==target) return mid1;
            if(nums[mid2]==target) return mid2;
            if(target<nums[mid1]){
                end = mid1-1;
            }
            else if(target>nums[mid2]){
                start = mid2+1;
            }
            else{
                start = mid1+1;
                end = mid2-1;
            }
        }
        return -1;
    }
};