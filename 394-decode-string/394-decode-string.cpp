class Solution {
public:
    string decodeString(string s) {
        stack<string> result;
        string res ="";
        stack<int> counts;
        int index =0;
        while(index<s.size()){
            if(isdigit(s[index])){
                int count=0;
                while(isdigit(s[index])){
                    count=count*10 +(int)(s[index]-'0');
                    index+=1;
                }
                counts.push(count);
            }
            else if(s[index]=='['){
                result.push(res);
                res = "";
                index+=1;
            }
            else if(s[index]==']'){
                string top = result.top();
                result.pop();
                int count = counts.top();
                counts.pop();
                for(int i=0;i<count;i++){
                        top+=res;
                }
                res = top;
                index+=1;
            }
            else{
                res+=s[index];
                index+=1;
            }
        }
        return res;
    }
};