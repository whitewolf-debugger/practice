class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start =0;
        int end = nums.size();
        int mid = (start+end)/2;
        int element = nums[mid];
        int ans  =0;
        for(int i=0;i<mid;i++){
            ans+=(element-nums[i]);
        }
        for(int j=mid+1;j<end;j++){
            ans+=(nums[j]-element);
        }
        return ans;
    }
};
/*


 1   2   9  10
 1   0   7   8 
 1   2   3

*/