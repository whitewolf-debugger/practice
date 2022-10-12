class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        vector<int> perimeters;
        for(int i =0; i < nums.size()-2;i++) {
            double a = nums[i];
            double b = nums[i+1];
            double c = nums[i+2];
            double perimeter = a + b+ c;
            double s = (a + b + c) /2;
            double mul = (s*(s-a)*(s-b)*(s-c));
            cout<<s<<endl;
            double area = sqrt(mul);
            if(area > 0){
                perimeters.push_back(perimeter);
            }
        }
        if(perimeters.empty()) return 0;
        sort(perimeters.rbegin(),perimeters.rend());
        return perimeters[0];
    }
};