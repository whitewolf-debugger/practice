class ATM {
public:
    unordered_map<long,long> mp;
    ATM() {
        mp[20]=0;
        mp[50]=0;
        mp[100]=0;
        mp[200]=0;
        mp[500]=0;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<banknotesCount.size();i++){
            if(i==0){
                mp[20]+=banknotesCount[i];
            }
            if(i==1){
                mp[50]+=banknotesCount[i];
            }
            if(i==2){
                mp[100]+=banknotesCount[i];
            }
            if(i==3){
                mp[200]+=banknotesCount[i];
            }
            if(i==4){
                mp[500]+=banknotesCount[i];
            }
        }
    }
    vector<int> withdraw(int amount) {
        vector<int>v(5,0);
        long ans =0;
        ans = amount/500;
        ans=min(ans,mp[500]);
        v[4]=ans;
        amount-=ans*500;
        ans =amount/200;
        ans=min(ans,mp[200]);
        v[3]=ans;
        amount-=ans*200;
        ans = amount/100;
        ans=min(ans,mp[100]);
        v[2]=ans;
        amount-=ans*100;
        ans = amount/50;
        ans=min(ans,mp[50]);
        v[1]=ans;
        amount-=ans*50;
        ans = amount/20;
        ans=min(ans,mp[20]);
        v[0]=ans;
        amount-=ans*20;
        if(amount!=0){
            vector<int>t;
            t.push_back(-1);
            return t;
        }
        mp[20]-=v[0];
        mp[50]-=v[1];
        mp[100]-=v[2];
        mp[200]-=v[3];
        mp[500]-=v[4];
        return v;

            
    }   
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */