class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,int> mp;
        unordered_map<string,int> visited;
        for(auto& a : bank){
            mp[a]++;
        }
        vector<char> mutations = {'A','C','G','T'};
        queue<string> pendingSequence;
        pendingSequence.push(start);
        int moves = 0;
        while(!pendingSequence.empty()){
            int size = pendingSequence.size();
            while(size--){
                string front = pendingSequence.front();
                pendingSequence.pop();
                if(front==end) return moves;
                for(int i=0;i<8;i++){
                    string temp = front;
                    for(auto& mutation : mutations){
                        temp[i]=mutation;
                        if(mp[temp] && !visited[temp]){
                            visited[temp]=true;
                            pendingSequence.push(temp);
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};