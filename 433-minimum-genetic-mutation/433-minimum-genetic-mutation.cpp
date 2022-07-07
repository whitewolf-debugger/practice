/*

Steps -

1. Make a map to mark all the mutations present in the bank
2. Make another map to mark all the visited mutations
3. Make a queue of strings and push the starting mutation in queue
4. Do a BFS traversal, until the queue is not empty
7. Pop the currunt mutation out of the string
8.If the current mutation is end mutation, return ans
9.For each character in the mutation, change each gene to get a new mutation and insert each new mutation in queue only if the new mutation is not visited and is present in the bank
10.I the queue becomes empty and we do not get the end mutation, ans is -1

*/
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
                //since the size of string will be 8 
                for(int i=0;i<8;i++){
                    //copy the front element 
                    string temp = front;
                    //since we want to mutate only 1 gene at a time so me donot do changes directly in front string we make copy
                    for(auto& mutation : mutations){
                        //change the character at that place do bfs 
                        temp[i]=mutation;
                        //if sequence is there in the bank and we have not seen the sequence we push the sequence in queue and mark visited
                        if(mp[temp] && !visited[temp]){
                            visited[temp]=true;
                            pendingSequence.push(temp);
                        }
                    }
                }
            }
            //increase moves 
            moves++;
        }
        return -1;
    }
};