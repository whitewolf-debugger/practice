bool compare(vector<int>& a , vector<int>& b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] > b[0];
}
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),compare);
        int count = 0;
        int maxdef = INT_MIN;
        for(int i = 0 ; i < properties.size();i++){
            if (maxdef > properties[i][1]){
                count++;
            }
             maxdef = max(maxdef,properties[i][1]);
        }
        return count;
    }
};
/*


//decreasing attacks and increasing defence 
    [6,3] , [5,5] ,[3,6]

    []

*/