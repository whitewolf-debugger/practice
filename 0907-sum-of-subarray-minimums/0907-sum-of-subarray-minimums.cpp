class Solution {
public:
    int sumSubarrayMins(vector<int>& n) {
        long long res = 0, sz = n.size(), mod = 1000000007;
        vector<int> ms{-1};
        for(long long i = 0; i <= sz; ++i) {
        while(ms.back() != -1 && (i == sz || n[i] <= n[ms.back()])) {
            int j = ms.back(); ms.pop_back();
            res = (res + n[j] * (j - ms.back()) * (i - j)) % mod;
        }
        ms.push_back(i);
    }
    return res;
    }
};