class Solution {
public:
    int maximum69Number (int num) {
        vector<int> n;
        while(num > 0) {
            int rem = num % 10;
            n.push_back(rem);
            num = num / 10;
        }
        reverse(n.begin(),n.end());
        int i =0;
        while(i < n.size() && n[i] == 9) {
            i++;
        }
        if(i < n.size()) {
            n[i] = 9;
        }
        int ans = 0;
        for(int j =0 ; j < n.size();j++) {
            ans = ans* 10 + n[j];
        }
        return ans;
    }
};