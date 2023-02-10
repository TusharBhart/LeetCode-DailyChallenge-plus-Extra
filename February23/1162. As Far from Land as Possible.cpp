class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), ans = -1;;
        vector<vector<int>> vis(n, vector<int>(n));
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) q.push({{i, j}, 0}), vis[i][j] = 1;
            }
        }
        vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

        while(q.size()) {
            int i = q.front().first.first, j = q.front().first.second;
            int d = q.front().second; q.pop();
            ans = max(ans, d);

            for(int k=0; k<4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if(x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && !grid[x][y]) {
                    q.push({{x, y}, d + abs(x - i) + abs(y - j)});
                    vis[x][y] = 1;
                }
            }
        }
        return ans ? ans : -1;
    }
};