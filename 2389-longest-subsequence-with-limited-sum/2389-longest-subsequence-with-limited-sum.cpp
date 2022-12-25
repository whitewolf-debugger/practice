class Solution {
public:
    int getSize(vector<int> & nums, int sum) {

        int count  =0 ;
        for(int i =0 ; i < nums.size() ; i++) {
            if(sum >= nums[i]) {
                sum -= nums[i];
                count++;
            }else {
                break;
            }
            
        }

        return count;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        sort(nums.begin(), nums.end());

        for(int i =0; i < m; i++) {
            ans[i] = getSize(nums, queries[i]);
        }
        return ans;
    }
};