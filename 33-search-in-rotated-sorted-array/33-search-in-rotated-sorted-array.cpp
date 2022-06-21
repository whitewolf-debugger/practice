class Solution {
public:
    int binarySearch(vector<int>& nums,int target,int start,int end){
        int mid;
        while(start<=end){
            mid = (start+end)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) end = mid-1;
            else start = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int L =0;
        int R =1;
        while(R<nums.size() && nums[L]<nums[R]){
            L++;
            R++;
        }
        int Left = binarySearch(nums,target,0,L);
        int Right = binarySearch(nums,target,R,nums.size()-1);
        if(Left!=-1) return Left;
        if(Right!=-1) return Right;
        return -1;
    }
};