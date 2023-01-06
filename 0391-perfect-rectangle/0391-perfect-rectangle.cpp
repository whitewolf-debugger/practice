class Solution {
public:
    string makeKey(long long x, long long y) {
        string ans ="";
        ans = to_string(x) + " " + to_string(y);
        return ans;
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long n =rectangles.size();
        unordered_set<string> corners;
        long long l_x = INT_MAX;
        long long l_y = INT_MAX;
        long long r_x = INT_MIN;
        long long r_y = INT_MIN;
        double area = 0;
        for(auto & point : rectangles) {
            l_x = min(l_x , (long long)point[0]);
            l_y = min(l_y, (long long)point[1]);
            r_x = max(r_x, (long long)point[2]);
            r_y = max(r_y, (long long)point[3]);
            area += ((double)((double)point[2] - point[0]) * ((double)point[3] - point[1]));
            string corner1 = makeKey(point[0] , point[1]);
            string corner2 = makeKey(point[0], point[3]);
            string corner3 = makeKey(point[2], point[1]);
            string corner4 = makeKey(point[2], point[3]);

            if(corners.find(corner1) != corners.end()) {
                corners.erase(corner1);
            } else {
                corners.insert(corner1);
            }
            if(corners.find(corner2) != corners.end()) {
                corners.erase(corner2);
            } else {
                corners.insert(corner2);
            }
            if(corners.find(corner3) != corners.end()) {
                corners.erase(corner3);
            } else {
                corners.insert(corner3);
            }
            if(corners.find(corner4) != corners.end()) {
                corners.erase(corner4);
            } else {
                corners.insert(corner4);
            }

        }
        string corner1 = makeKey(l_x , l_y);
        string corner2 = makeKey(l_x, r_y);
        string corner3 = makeKey(r_x, r_y);
        string corner4 = makeKey(r_x, l_y);

        if(corners.size() != 4) {
            return false;
        }

        if(!corners.count(corner1) ||!corners.count(corner2) || !corners.count(corner3) || !corners.count(corner4) ) {
            return false;
        }
        
        return area == (r_x - l_x) * (r_y - l_y);
    }
}; 