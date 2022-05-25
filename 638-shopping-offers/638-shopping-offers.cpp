class Solution {
public:
    bool isUsefulOffer(vector<int> &special,vector<int> &needs){
        for(int i=0;i<needs.size();i++){
            //if in offer any product is morethan what we need we return false and donot consider that offer
            if(needs[i]<special[i]) return false;
        }
        //if we came out of for loop means that the offer is suitable for us and we proceed to do backtracking
        return true;
    }
    int remaining(vector<int> needs,vector<int> price){
        int sum=0;
        //adds the remaining price
        for(int i =0;i<needs.size();i++){
            sum+=needs[i]*price[i];
        }
        //return the sum of price of remaining needed items
        return sum;
    }
    vector<int> updateNeeds(vector<int> special,vector<int> needs,char op){
        for(int i=0;i<needs.size();i++){
            if(op=='-'){
                //if operation is - then we subtract the quantity of product needed with qty in the offer
                needs[i]-=special[i];
            }
            else{
                //if operation is + then we subtract the quantity of product needed with qty in the offer  for backtracking
                needs[i]+=special[i];
            }
        }
        //return the updated needs list
        return needs;
    }
    void dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,int currentPrice,int &ans){
        //check if all the quantity needed is 0
        if(accumulate(needs.begin(), needs.end(), 0) == 0){
            // if all the quantity needed becomes 0 
            ans = min(ans,currentPrice);
            return;
        }
        //discovering every path from each index 
        for(int i=0;i<special.size();i++){
            // if the quantity of product we need is eligible for the offer 
            if(isUsefulOffer(special[i],needs)){
                //increase the current price 
                currentPrice+=special[i].back();
                //take that amount of products in offer 
                needs = updateNeeds(special[i],needs,'-');
                //discover price if we take this offer 
                dfs(price,special,needs,currentPrice,ans);
                //backtracking step revert back to original values of price and quantity needed
                needs = updateNeeds(special[i],needs,'+');
                //discover all other possibilities
                currentPrice-=special[i].back();
            }
        }
        //if at the end we check that the using the offer we didnot take all the needed items
        if(accumulate(needs.begin(), needs.end(), 0) != 0){
            //take the needed items which are remaining and add their individual price to the current price 
            currentPrice+=remaining(needs,price);
            //ans will be minimum of ans and current price 
            ans = min(ans,currentPrice);
            return;
        }
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        //ans is passed by reference stores the ans 
        int ans=INT_MAX;
        int currentPrice;
        //do dfs and ans will be stored in ans
        dfs(price,special,needs,0,ans);
        return ans;
    }
};