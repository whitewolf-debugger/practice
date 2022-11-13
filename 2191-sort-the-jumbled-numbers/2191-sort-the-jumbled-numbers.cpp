class Solution {
public:
    //comparing the pair we create the condition 
    static bool compare(pair<int , int> & a, pair<int , int> &b) {
        return a.first < b.first;
    }
    //this decodes the num base case if the num is 0 then we return the mapping at 0 
    int newNum(vector<int>& mapping,int num) {
        if(num == 0) {
            return mapping[0];
        }
        vector<int> number;
        //create the number store it in the number vector by mapping with respect to the given number
        while(num > 0) {
            int rem = num % 10;
            number.push_back(mapping[rem]);
            num = num / 10;
        }
        //reverse it since extracting the number it gets reversed map number is in reversed form 
        reverse(number.begin(),number.end());
        //store the number vrom vector to integer number in ans and return it 
        int ans = 0;
        for(int i =0 ; i < number.size(); i++) {
            ans *= 10;
            ans += number[i];
        }
        return ans;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        //stores the newnumber and the original pair 
        vector<pair<int , int>> map;
        for(int i =0 ; i < nums.size();i++) {
            map.push_back({newNum(mapping,nums[i]),nums[i]});
        }
        //pair of newnumber and the original pair  is sorted on the basis of 1st number which is the new number after mapping 
        sort(map.begin(),map.end(),compare);
        //store the second number i.e. the original number in sorted order after sorting the pairs
        vector<int> ans;
        for(int i =0 ; i < map.size(); i++) {
            ans.push_back(map[i].second);
        }
        return ans;
    }
};