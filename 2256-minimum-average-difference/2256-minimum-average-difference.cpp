class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long int ans = INT_MAX;
        int i=0;
        int minindex=0;
        unordered_map<long int,long int> smp;
        unordered_map<long int,long int> rmp;
        long int sum1 =0;
        long int sum2=0;
        for(int i=0;i<nums.size();i++){
            sum1+=nums[i];
            smp[i]=sum1;
        }
        for(int i=nums.size()-1;i>=0;i--){
            sum2+=nums[i];
            rmp[i]=sum2;
        }
        for(int i=0;i<nums.size();i++){
            long int n1=i+1;
            long int n2=nums.size()-i-1;
            long int avg1 = smp[i]/n1;
            long int avg2 = (n2!=0)?rmp[i+1]/n2:0;
            long int diff =avg1-avg2;
            diff = abs(diff);
            if(ans>diff){
                minindex =i;
                ans = diff;
            }
        }
        return minindex;
    }
};