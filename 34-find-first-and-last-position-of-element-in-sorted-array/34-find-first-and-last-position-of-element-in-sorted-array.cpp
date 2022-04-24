class Solution {
    int firstIndex(vector<int>& num,int startIndex,int maxsize,int target){
        if(startIndex>=maxsize){
            return -1;
        }
        if(num[startIndex]==target){
            return startIndex;
        }
        int index = firstIndex(num,startIndex+1,maxsize,target);
        return index;
    }
    int LastIndex(vector<int>& num,int maxsize,int target){
        if(maxsize<0){
            return -1;
        }
        if(num[maxsize]==target){
            return maxsize;
        }
        int lastIndex = LastIndex(num,maxsize-1,target);
        return lastIndex;
    }
public:
    vector<int> searchRange(vector<int>& num, int target) {
        int firstindex =0;
        int Lastindex = num.size()-1;
        vector<int> v;
        int first = firstIndex(num,firstindex,num.size(),target);
        int last = LastIndex(num,Lastindex,target);
        v.push_back(first);
        v.push_back(last);
        return v;
    }
};