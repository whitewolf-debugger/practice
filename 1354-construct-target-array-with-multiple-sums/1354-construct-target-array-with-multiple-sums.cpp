class Solution {
public:
    bool isPossible(vector<int>& target) {
        long int maxIndex = 0;
        long int sum =0;
        for(int i =0;i<target.size();i++){
            //find out sum of all element
            sum+=target[i];
            if(target[i]>target[maxIndex]){
                //find out index of largest element
                maxIndex = i;
            }
        }
        //find difference of maxvalue with the total sum 
        long int diff = sum - target[maxIndex];
        // base cases 
        if(target[maxIndex]==1 || diff ==1) return true;
        if(diff>target[maxIndex] || diff ==0 || target[maxIndex]%diff==0) return false;
        //replacing the element at maxindex with 1 
        target[maxIndex]%=diff;
        //recirsive call 
        return isPossible(target);
    }
};