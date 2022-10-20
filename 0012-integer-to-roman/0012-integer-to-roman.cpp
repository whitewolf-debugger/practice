class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        vector<pair<int,string>> nums = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"}, 
            {400, "CD"}, 
            {100, "C"},
            {90, "XC"}, 
            {50, "L"}, 
            {40, "XL"}, 
            {10, "X"}, 
            {9, "IX"}, 
            {5, "V"},
            {4, "IV"}, 
            {1, "I"}
        };
        for(auto & x: nums) {
            if(num > 0) {
                while(num >= x.first) {
                    ans += x.second;
                    num -= x.first;
                }
            }
        }
        return ans;
    }
};