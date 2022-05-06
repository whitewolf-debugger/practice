class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int,int>> stk;
        for(char c : s){
            if(stk.empty()){
                stk.push({c,1});
            }
            else{
                auto top = stk.top();
                char prev = top.first;
                int currentstreak =top.second;
                if(prev == c){
                    stk.pop();
                    int newstreak = currentstreak+1;
                    if(newstreak<k){
                        stk.push({c,newstreak});
                    }
                }
                else{
                    stk.push({c,1});
                }
            }
        }
        string ans="";
        while(!stk.empty()){
            auto top = stk.top();
            char c = top.first;
            stk.pop();
            int howmany = top.second;
            for(int i=0;i<howmany;i++){
                ans+=c;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/*

   deeedbbcccbdaa
   ^
   k=3
   
   







*/