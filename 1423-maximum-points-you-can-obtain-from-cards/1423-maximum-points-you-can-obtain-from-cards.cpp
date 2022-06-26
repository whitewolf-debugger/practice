class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans;
        int curr =0;
        int n = cardPoints.size();
        for(int i=0 ;i<k;i++){
            curr+=cardPoints[i];
        }
        ans = curr;
        for(int i = k-1;i>=0;i--){
            curr-=cardPoints[i];
            curr+=cardPoints[n-k+i];
            ans = max(ans,curr);
        }
        return ans;
    }
};
/*

  1 , 2 , 3 , 4 , 5 , 6 , 1
  
  0   1   2   3   4   5   6
  
          i = 2
          n = 7-3
          5
     




*/
