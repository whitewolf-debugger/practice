class Solution {
public:
    int side1,side2,side3,side4;
    bool makesquare(vector<int>& matchsticks,int currIndex){
        if(currIndex==matchsticks.size()){
            if(side1==0 && side2==0 && side3==0 && side4 ==0){
                return true;
            }
            else return false;
        }
        if(matchsticks[currIndex]<=side1){
            side1-=matchsticks[currIndex];
            if(makesquare(matchsticks,currIndex+1)) return true;
            side1+=matchsticks[currIndex];
        }
        if(matchsticks[currIndex]<=side2){
             side2-=matchsticks[currIndex];
            if(makesquare(matchsticks,currIndex+1)) return true;
            side2+=matchsticks[currIndex];
        }
        if(matchsticks[currIndex]<=side3){
            side3-=matchsticks[currIndex];
            if(makesquare(matchsticks,currIndex+1)) return true;
            side3+=matchsticks[currIndex];
        }
        if(matchsticks[currIndex]<=side4){
            side4-=matchsticks[currIndex];
            if(makesquare(matchsticks,currIndex+1)) return true;
            side4+=matchsticks[currIndex];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        //if size of the matchsticks is less than 4 means we cannot make 4 sides 
        if(matchsticks.size()<4) return false;
        int totalsum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(totalsum%4!=0) return false;
        int sidesum = totalsum/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        side1 = sidesum;
        side2 = sidesum;
       side3 = sidesum;
        side4 = sidesum;
        return makesquare(matchsticks,0);
    }
};