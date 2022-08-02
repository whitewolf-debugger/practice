class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        priority_queue<int> pq;
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(pq.size()<k){
                    pq.push(matrix[i][j]);
                }
                else{
                    if(pq.top()>matrix[i][j]){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};