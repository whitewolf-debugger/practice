class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<pair<int,int>> pendingNodes;
        pendingNodes.push({0,0});
        set<int> forbid;
        set<int> seen1;
        int level =0;
        set<int> seen2;
        for(auto& x:forbidden){
            forbid.insert(x);
        }
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            while(size--){
                pair<int,int> front  = pendingNodes.front();
                pendingNodes.pop();
                int pos = front.first;
                int flag = front.second;
                if(pos ==x) return level;
                if(flag){
                        if(forbid.find(pos+a)==forbid.end())
                        if( seen1.find(pos+a)==seen1.end() && pos+a<=6000){
                            if(pos+a==x)
                            return level+1;
                            pendingNodes.push({pos+a,0});
                            seen1.insert(pos+a);
                        }

                }
                else{
                    if(forbid.find(pos+a)==forbid.end())
                    if( seen1.find(pos+a)==seen1.end() && pos+a<=6000){
                        if(pos+a==x)
                        return level+1;
                        pendingNodes.push({pos+a,0});
                        seen1.insert(pos+a);
                    }

                    if(forbid.find(pos-b)==forbid.end())

                    if( seen2.find(pos-b)==seen2.end() && pos-b>=0){
                        if(pos-b==x)
                        return level+1;
                        pendingNodes.push({pos-b,1});
                        seen2.insert(pos-b);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};