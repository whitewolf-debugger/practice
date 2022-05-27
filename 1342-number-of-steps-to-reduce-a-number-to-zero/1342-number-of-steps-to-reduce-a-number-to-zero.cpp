class Solution {
public:
    int numberOfSteps(int num) {
        int numsteps =0;
        while(num>0){
            if(num%2==0){
                num = num/2;
            }
            else num=num-1;
            numsteps++;
        }
        return numsteps;
    }
};