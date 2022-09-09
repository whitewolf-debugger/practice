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
 THE DEFENCE ARE SORTED IN INCREASING ORDER WHEN ATTACK ARE SAME -: because if the attack are same because the restriction id attack and defence has to be strictly greater so attack cannot be same 
    1. sort the first one attack in descending order 
    2. the next elements are having either equal or smaller defence 
    3. keep the track of max defence 
    4.if the max defence is greater than current elements defence then increase count and keep on updating max defence  
*/