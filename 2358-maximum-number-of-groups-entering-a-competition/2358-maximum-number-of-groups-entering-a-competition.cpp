class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int s= grades.size();
        return (-1+sqrt(1+8*s))/2;
    }
};