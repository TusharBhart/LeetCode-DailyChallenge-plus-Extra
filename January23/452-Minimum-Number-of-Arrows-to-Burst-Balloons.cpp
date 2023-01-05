class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1, last = points[0][1], n = points.size();

        for(int i=1; i<n; i++) {
            if(last < points[i][0]) ans++, last = points[i][1];
            else last = min(last, points[i][1]);
        }
        return ans;
    }
};