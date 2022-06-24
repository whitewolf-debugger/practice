class Solution {
public:
    bool isPossible(vector<int>& target) {
        long int maxIndex = 0;
        long int sum =0;
        for(int i =0;i<target.size();i++){
            sum+=target[i];
            if(target[i]>target[maxIndex]){
                maxIndex = i;
            }
        }
        long int diff = sum - target[maxIndex];
        if(target[maxIndex]==1 || diff ==1) return true;
        if(diff>target[maxIndex] || diff ==0 || target[maxIndex]%diff==0) return false;
        target[maxIndex]%=diff;
        return isPossible(target);
    }
};