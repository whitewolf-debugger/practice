class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1000000007;
        long result = 0;
        for (int i = 1; i <= n; i++) {
            // use a int array to represent the binary
            int length = (int)log2(i) + 1;
            int binary[length];
            int temp = i;
            // keep divide 2 and put into the binary array
            for (int index = length - 1; index >= 0; index--) {
                binary[index] = (temp % 2 == 0 ? 0 : 1);
                temp /= 2;
            }
            // append the value to the result
            for (int j = 0; j < length; j++) {
                result = (result * 2 + binary[j]) % MOD;
            }
        }
        return result;
    }
};