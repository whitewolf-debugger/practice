class Solution {
public:
    const string keycode[10]={"", "", "abc", "def", "ghi", "jkl", "mno","pqrs", "tuv", "wxyz"};
    void helper(int digits,string output,vector<string> &ans){
        if(digits==0){
            ans.push_back(output);
            return;
        }
        int smallnum = digits%10;
        string code = keycode[smallnum];
        for(int i=0;i<code.size();i++){
            helper(digits/10,code[i]+output,ans);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        int num=0;
        for(int i=0;i<digits.size();i++){
            num=num*10+(int)(digits[i]-'0');
        }
        helper(num,"",ans);
        return ans;
    }
};