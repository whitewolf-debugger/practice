class Solution {
public:
    //check for the closest value to the target 
    int closest(int a,int b,int target){
        if(a==0) return b;
        if(b==0) return a;
        if(abs(target-a)==abs(target-b)){
            return a<b?a:b;
        }
        return abs(target-a)<abs(target-b)?a:b;
    }
    int backtrack(vector<int>& toppingsCosts,int i,int sum,int target){
        if(i>=toppingsCosts.size()) return sum;
        // we can either take 2 toppings or 1 topping or no topping 
        int a = backtrack(toppingsCosts,i+1,sum+toppingsCosts[i],target);
        int b = backtrack(toppingsCosts,i+1,sum+toppingsCosts[i]*2,target);
        int c = backtrack(toppingsCosts,i+1,sum,target);
        //return closest of 3 value 
        return closest(a,closest(b,c,target),target);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans =0;
        for(auto base : baseCosts){
            //ans is closest target
            ans = closest(backtrack(toppingCosts,0,base,target),ans,target);
        }
        return ans;
    }
};
/*
n ice cream base flavor
m types of toppings 
There must be exactly one ice cream base.
You can add one or more types of topping or have no toppings at all.
There are at most two of each type of topping.



*/