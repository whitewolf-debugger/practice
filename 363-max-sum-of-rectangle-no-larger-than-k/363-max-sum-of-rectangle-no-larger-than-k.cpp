class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int ans = INT_MIN;
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        
        for(int L = 0; L < COLS; L++){
            
            vector<int> sums(ROWS);
            
            for(int R = L; R < COLS; R++){
                for(int i = 0; i < ROWS; i++){
                    
                    sums[i] += matrix[i][R];        
                }
                
                set<int> s = {0};
                int curr_sum = 0;

                for(int sum : sums) {
                    curr_sum += sum;
                    auto it = s.lower_bound(curr_sum - k);
                    if(it != s.end()) {
                        ans = max(ans, curr_sum - *it);
                    }
                    s.insert(curr_sum);
                }
            }
        }
        return ans;
    }
};
/*
    k = 2
    
            R
    L
    1   0   1
    0  -2   3




*/