class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char , int> mp;
        int n = magazine.size();
        
        for(int i =0; i < n; i++){
            mp[magazine[i]]++;
        }
        
        for(int i = 0; i < ransomNote.size(); i++){
            
            if(mp[ransomNote[i]] <=0){
                return false;
            }
            mp[ransomNote[i]]--;
        }
        
        return true;
    }
};