class Solution {
public:
    char nextchar(char curr){
        char ans = curr+1;
        return ans>'9'?'0':ans;
    }
    char prevchar(char curr){
        char ans = curr-1;
        return ans<'0'?'9':ans;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadend;
        for(auto& x: deadends){
            deadend.insert(x);
        }
        int step =0;
        queue<string> sequence;
        sequence.push("0000");
        unordered_map<string,bool> visited;
        visited["0000"]=true;
        if(deadend.find("0000")!=deadend.end()) return -1;
        while(!sequence.empty()){
            int size = sequence.size();
            while(size--){
                string front = sequence.front();
                sequence.pop();
                if(front==target) return step;
                for(int i=0;i<4;i++){
                    string temp = front;
                    temp[i] = prevchar(front[i]);
                    if(deadend.find(temp)==deadend.end() && !visited[temp]){
                        sequence.push(temp);
                        visited[temp]=true;
                    }
                    temp[i] = nextchar(front[i]);
                    if(deadend.find(temp)==deadend.end() && !visited[temp]){
                        sequence.push(temp);
                        visited[temp]=true;
                    }
                }
            }
            step+=1;
        }
        return -1;
    }
};