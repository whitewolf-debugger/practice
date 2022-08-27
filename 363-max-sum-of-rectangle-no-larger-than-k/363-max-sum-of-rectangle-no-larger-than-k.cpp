class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int ans = INT_MIN;
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        
        for(int L = 0; L < COLS; L++){
            
            //create a vector sums of size rows , it stores sum of element of that row of rectange L to COLS and 0 to ROWS in size
            vector<int> sums(ROWS);
            
            for(int R = L; R < COLS; R++){
                
                // sum of element of indivul rows where R is fixed 
                for(int i = 0; i < ROWS; i++){
                    
                    // Calculating the sum of the element of Rth Column and ith Row
                    sums[i] += matrix[i][R];        
                }
                //set stores the running / current  sum 
                set<int> s = {0};
                
                // current sum is used to calculate the current sum or running sum 
                int curr_sum = 0;
                
                // traverse through sums and we follow the prefix sums approach 
                for(int sum : sums) {
                    
                    //calculate the current sum 
                    curr_sum += sum;
                    
                    // get value less than and very close to  current_sum - k 
                    auto it = s.lower_bound(curr_sum - k);
                    
                    //if that element exist in the set
                    if(it != s.end()) {
                        
                        // ans is max of previous ans and current found element 
                        ans = max(ans, curr_sum - *it);
                    }
                    
                    // insert the running sum in ans
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
   i    ->      1   0   1
                0  -2   3




*/