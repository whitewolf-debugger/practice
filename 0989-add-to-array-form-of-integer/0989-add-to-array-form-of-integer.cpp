class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> sol;
        vector<int> add;
        reverse(num.begin(), num.end());
        int carry = 0;
        while(k > 0) {
            add.push_back(k % 10);
            k = k / 10;

        }
        int sum = 0;
        int i = 0;
        int j = 0;
        while(i < add.size() && j < num.size()) {
            sum = add[i] + num[j] + carry;
            carry = sum > 9 ? 1: 0;
            sum = sum % 10;
            sol.push_back(sum);
            i++;
            j++;
            
        }
        while(i < add.size()) {
            sum = add[i] + carry;
            carry = sum > 9 ? 1: 0;
            sum = sum % 10;
            sol.push_back(sum);
            i++;
        }
        while(j < num.size()) {
            sum = num[j] + carry;
            carry = sum > 9 ? 1: 0;
            sum = sum % 10;
            sol.push_back(sum);
            j++;
        }
        if(carry > 0) {
            sol.push_back(carry);
        }
        reverse(sol.begin(), sol.end());

        return sol;
    }
};