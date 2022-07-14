class Solution {
public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        while(!q.empty())
        {
            auto temp=q.front();
            string word=temp.first;
            int ladder=temp.second;
            q.pop();
            if(word==endWord)
            {
                return ladder;
            }
            st.erase(word);
            //example "hit"
            for(int i=0;i<word.size();i++)
            {
                //keep the current character so that you can replace it to its original place after use
                char c=word[i];
                for(int j=0;j<26;j++)
                {
                    word[i]='a'+j;
                    //search the changed word in dictionary
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,ladder+1});
                    }
                }
                //make the word as before to continue changing other character
                word[i]=c;
            }
        }
        return 0;
    }
};
