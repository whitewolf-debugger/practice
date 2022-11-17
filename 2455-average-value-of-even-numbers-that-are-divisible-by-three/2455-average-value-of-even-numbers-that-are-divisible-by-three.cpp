class Solution {
public:
    int averageValue(vector<int>& nums) {
        vector<int> div;
        for(int i =0 ; i < nums.size(); i++) {
            if((nums[i] % 2 == 0) && (nums[i] % 3 == 0)) {
                div.push_back(nums[i]);
            }
        }
        int n = div.size();
        if(n == 0) return 0;
        int sum = accumulate(div.begin(),div.end(),0);
        return sum/n;
    }
};