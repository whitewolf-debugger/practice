class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        unordered_map<int,int> mp;
        //count frequencies of all the character store it in a map 
        for(auto & a:s){
            mp[a]++;
        }
        //iterate through map keep a check of the frequencies
        unordered_set<int> seen;
        for(auto&um:mp){
            //of frequency of current element is already there means 2 elements have same frequency
            if(seen.find(um.second)!=seen.end()){
                //drease the frequency of current element till it is not in seen set or unique
                while(seen.find(um.second)!=seen.end() && um.second>0){
                    //increase the ans as we do operations by decreasing frequency 
                    ans++;
                    um.second--;
                }
            }
            //finally insert the chaged frequency or if it was unique change doesnot happens and frequncy is inserted 
            seen.insert(um.second);
        }
        //return the ans 
        return ans;
    }
};