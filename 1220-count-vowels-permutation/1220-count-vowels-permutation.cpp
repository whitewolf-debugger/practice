class Solution {
public:
    int countVowelPermutation(int n) {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int x = 1; x < n; ++x) {
                tie(a, e, i, o, u) = make_tuple(((e + i) % MOD +u) % MOD,(a + i) % MOD,(e + o) % MOD,i,(i + o) % MOD);
        }
        return (((a + e) % MOD + (i + o) % MOD) % MOD + u) %MOD;
        }
        private:
            const int MOD = 1e9 + 7;
};