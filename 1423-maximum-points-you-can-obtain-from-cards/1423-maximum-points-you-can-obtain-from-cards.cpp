class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans;
        int curr =0;
        int n = cardPoints.size();
        //assing first k elements
        for(int i=0 ;i<k;i++){
            curr+=cardPoints[i];
        }
        ans = curr;
        //remove element from last of k window and one from the end of the array get the max
        for(int i = k-1;i>=0;i--){
            curr-=cardPoints[i];
            curr+=cardPoints[n-k+i];
            ans = max(ans,curr);
        }
        return ans;
    }
};
/*
  sliding window approach
  
  1  2  3 | 4  5  6  1
  
  sum =  1 + 2 + 3 =6
 
  1  2 | 3   4  5  6 | 1
  
  sum = 1 + 2 + 1 = 4
  
  1 | 2  3   4  5 | 6  1
  
  sum = 1 + 6 + 1 = 8
  
  1  2  3   4 | 5  6  1
  
  sum = 5 + 6 + 1 = 12
  
  ANS  = MAXIMUM  = 12

*/
