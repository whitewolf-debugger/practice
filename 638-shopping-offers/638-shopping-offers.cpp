class Solution {
public:
    bool isUsefulOffer(vector<int> &special,vector<int> &needs){
        for(int i=0;i<needs.size();i++){
            if(needs[i]<special[i]) return false;
        }
        return true;
    }
    int remaining(vector<int> needs,vector<int> price){
        int sum=0;
        for(int i =0;i<needs.size();i++){
            sum+=needs[i]*price[i];
        }
        return sum;
    }
    vector<int> updateNeeds(vector<int> special,vector<int> needs,char op){
        for(int i=0;i<needs.size();i++){
            if(op=='-'){
                needs[i]-=special[i];
            }
            else{
                needs[i]+=special[i];
            }
        }
        return needs;
    }
    void dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,int currentPrice,int &ans){
        if(accumulate(needs.begin(), needs.end(), 0) == 0){
            ans = min(ans,currentPrice);
            return;
        }

        for(int i=0;i<special.size();i++){
            if(isUsefulOffer(special[i],needs)){
                currentPrice+=special[i].back();
                needs = updateNeeds(special[i],needs,'-');
                dfs(price,special,needs,currentPrice,ans);
                needs = updateNeeds(special[i],needs,'+');
                currentPrice-=special[i].back();
            }
        }
        if(accumulate(needs.begin(), needs.end(), 0) != 0){
            currentPrice+=remaining(needs,price);
            ans = min(ans,currentPrice);
            return;
        }
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ans=INT_MAX;
        int currentPrice;
        dfs(price,special,needs,0,ans);
        return ans;
    }
};