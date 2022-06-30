class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //sort the array 
        sort(nums.begin(),nums.end());
        int start =0;
        int end = nums.size();
        //get mid index 
        int mid = (start+end)/2;
        //get middle element 
        int element = nums[mid];
        int ans  =0;
        //element less than mid are smaller since it is sorted arry so add the difference element-nums[i] (number of steps)
        for(int i=0;i<mid;i++){
            ans+=(element-nums[i]);
        }
         //element greater than mid are smaller since it is sorted arry so add the difference nums[j]-element (number of steps)
        for(int j=mid+1;j<end;j++){
            ans+=(nums[j]-element);
        }
        //return ans
        return ans;
    }
};
/*

 elements of the array -:
 1   2   9  10     
 
     mid = 4/2  =2
     
     mid element  =9;
     
 absolute difference of each element from mid -:
 8   7   0   1
*/