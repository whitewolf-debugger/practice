class Solution {
public:
    //since we can rotate that lock once up so if we roate up we calculate next character if it is greater than 9 in the lock it is 0
    char nextchar(char curr){
        char ans = curr+1;
        return ans>'9'?'0':ans;
    }
    //since we can rotate that lock once down so if we roate down we calculate previous character if it is less than 0 in the lock it is 9
    char prevchar(char curr){
        char ans = curr-1;
        return ans<'0'?'9':ans;
    }
    int openLock(vector<string>& deadends, string target) {
        //create a set deadend and insert all the deadend in it 
        unordered_set<string> deadend;
        for(auto& x: deadends){
            deadend.insert(x);
        }
        //step stores the ans 
        int step =0;
        //sequence is queue which we use for bfs 
        queue<string> sequence;
        //push the first sequence 0000 in the queue and mark it visited
        sequence.push("0000");
        unordered_map<string,bool> visited;
        visited["0000"]=true;
        if(deadend.find("0000")!=deadend.end()) return -1;
        //do bfs 
        while(!sequence.empty()){
            int size = sequence.size();
            while(size--){
                string front = sequence.front();
                sequence.pop();
                //if we have reaced the target means front is the target return the steps 
                if(front==target) return step;
                for(int i=0;i<4;i++){
                    //create a copy of front string 
                    string temp = front;
                    //change to previous character at index i of copy we created of front string and stored in temp and do dfs 
                    temp[i] = prevchar(front[i]);
                    //if it is valid sequence after changeing the character at index i push in the queue 
                    if(deadend.find(temp)==deadend.end() && !visited[temp]){
                        sequence.push(temp);
                        visited[temp]=true;
                    }
                    //change to the next  character at index i of copy we created of front string and stored in temp  and do dfs 
                    temp[i] = nextchar(front[i]);
                    //if it is valid sequence after changeing the character at index i push in the queue 
                    if(deadend.find(temp)==deadend.end() && !visited[temp]){
                        sequence.push(temp);
                        visited[temp]=true;
                    }
                }
            }
            //increase the steps 
            step+=1;
        }
        // if nothing is returned means ans is -1 
        return -1;
    }
};