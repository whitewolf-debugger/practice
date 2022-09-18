class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0 , index = 0 , n = height.size();
        stack<int> st;
        while(index < n){
            while(!st.empty() && height[index] > height[st.top()]){
                int top = st.top();
                st.pop();
                if(st.empty()) break;
                int distance = index - st.top() - 1;
                int height_bound = min(height[index],height[st.top()]) - height[top];
                ans += distance * height_bound;
            }
            st.push(index++);
        }
        return ans;
    }
};