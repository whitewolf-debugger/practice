class Solution {
public:
    //for comparision 
    bool compare(vector<int>& mp,vector<int>& um){
        for(int i=0;i<26;i++){
            if(mp[i]!=um[i])return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> phash(26,0);
        //shash acts as window 
        vector<int> shash(26,0);
        int n1 = s.size();
        int n2 = p.size();
        //ans stores the finalans 
        vector<int> ans;
        if(s.size()<p.size()) return ans;
        for(int i=0;i<p.size();i++){
            //makse map phash 
            phash[p[i]-'a']++;
            //shash acts as window starting from 0 and end at p.size()-1
            shash[s[i]-'a']++;
        }
        //if shash and phash are same at the starting then and 0th index to the ans array 
        if(compare(phash,shash)) ans.push_back(0);
        for(int i = p.size();i<s.size();i++){
            //add element to the end of window 
            shash[s[i]-'a']++;
            //remove element from the starting 
            shash[s[i-p.size()]-'a']--;
            if(compare(shash,phash)){
                //push the starting index in the ans 
                ans.push_back(i+1-p.size());
            }
        }
        return ans;
    }
};
/*

    :a: |b  a|  b
          
   0  1  p.size()
          i
   
   
   ans.push();
   
   a  b 
   
   n1 = 4;
   n2 = 2
   




*/