class Solution {
public:
    int editDist(string word1,string word2,int **output){
        int m= word1.size();
        int n= word2.size();
        if(word1.size()==0 || word2.size()==0){
            return max(word1.size(),word2.size());
        }
        if(output[m][n] != -1){
            return output[m][n];
        }
        int ans;
        if(word1[0]==word2[0]){
            ans = editDist(word1.substr(1),word2.substr(1),output);
        }
        else{
            //insert 
            int a = editDist(word1.substr(1),word2,output)+1;
            //delete
            int b = editDist(word1,word2.substr(1),output)+1;
            //replace
            int c = editDist(word1.substr(1),word2.substr(1),output)+1;
            ans =min(a,min(b,c));
        }
        output[m][n]=ans;
        return output[m][n];
    }
    int editMem(string word1,string word2){
        int m = word1.size();
        int n = word2.size();
        int **output=new int*[m+1];
        for(int i=0;i<=m;i++){
            output[i] = new int[n+1];
            for(int j=0;j<=n;j++){
                output[i][j]=-1;
            }
        }
        return editDist(word1,word2,output);
    }
    int minDistance(string word1, string word2) {
        return editMem(word1,word2);
    }
};