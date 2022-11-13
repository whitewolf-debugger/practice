class Solution {
public:
    static bool compare(pair<int , int> & a, pair<int , int> &b) {
        return a.first < b.first;
    }
    int newNum(vector<int>& mapping,int num) {
        if(num == 0) {
            return mapping[0];
        }
        vector<int> number;
        while(num > 0) {
            int rem = num % 10;
            number.push_back(mapping[rem]);
            num = num / 10;
        }
        reverse(number.begin(),number.end());
        int ans = 0;
        for(int i =0 ; i < number.size(); i++) {
            ans *= 10;
            ans += number[i];
        }
        return ans;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int , int>> map;
        for(int i =0 ; i < nums.size();i++) {
            map.push_back({newNum(mapping,nums[i]),nums[i]});
        }
        sort(map.begin(),map.end(),compare);
        vector<int> ans;
        for(int i =0 ; i < map.size(); i++) {
            ans.push_back(map[i].second);
        }
        return ans;
    }
};