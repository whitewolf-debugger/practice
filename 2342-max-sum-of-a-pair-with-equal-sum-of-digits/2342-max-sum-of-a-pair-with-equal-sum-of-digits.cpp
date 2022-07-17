class Solution {
public:
    int Digsum(int num){
        int ans =0;
        while(num>0){
            int rem = num%10;
            ans+=rem;
            num = num/10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        int ans =-1;
        //make map of all the sum of digits  and numbers  
        unordered_map<int,vector<int>> mp;
        vector<int> digsum(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            //calculate the digit sum 
            digsum[i]=Digsum(nums[i]);
            //push the number at that index 
            mp[digsum[i]].push_back(nums[i]);
        }
        for(auto& x:mp){
            //elements sotres the elements that have same digit sum and different index 
            vector<int> elements  = x.second;
            //sort it in descending order 
            sort(elements.rbegin(),elements.rend());
            //if there are no 2 elements with same digit sum so we donot do anything for that digitsum 
            if(elements.size()<2) continue;
            //1st 2 element are greateast so add them and compare with ans 
            int sum  = elements[0]+elements[1];
            ans = max(ans,sum);
        }
        return ans;
    }
};