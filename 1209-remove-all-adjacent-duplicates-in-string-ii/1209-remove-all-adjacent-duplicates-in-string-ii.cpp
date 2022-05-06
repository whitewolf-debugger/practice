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
                // if the stack is not empty the prev character and current are same
                if(prev == c){
                    stk.pop();
                    //pop the character from stack
                    int newstreak = currentstreak+1;
                    //calculate new streak if it is less than k then push it in stack else we dont do anything
                    if(newstreak<k){
                        stk.push({c,newstreak});
                    }
                }
                else{
                    //if current and prev element are not same push character and its streak as 1
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
            //add that caracter number of times it was present 
            for(int i=0;i<howmany;i++){
                //rebuild the ans string
                ans+=c;
            }
        }
        //reverse the ans since we are using stacks 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
/*
    Keep a stack with the character and it's streak.
    If the steak is equal to K, then remove it from the stack.
    rebuild the string and reverse it to get the final answer.
*/
