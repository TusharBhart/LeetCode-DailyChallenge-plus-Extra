class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 1;
        for(int i=0; i<n; i++) {
            unordered_map<double, int> m;
            int x1 = points[i][0], y1 = points[i][1];
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                int x2 = points[j][0], y2 = points[j][1];
                double slope = (double) (y2 - y1) / (double) (x2 - x1);
                m[slope]++;
            }
            for(auto it : m) ans = max(ans, it.second + 1);
        }
        return ans;
    }
};