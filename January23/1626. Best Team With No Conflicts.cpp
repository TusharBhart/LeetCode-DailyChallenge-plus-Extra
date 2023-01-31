class Solution {
    int dfs(int i, int last, int n, vector<pair<int, int>> &v, vector<vector<int>> &dp) {
        if(i == n) return 0;
        if(dp[i][last] != -1) return dp[i][last];

        int notPick = dfs(i + 1, last, n, v, dp);
        int pick = v[i].second >= last ? v[i].first + dfs(i + 1, v[i].second, n, v, dp) : 0;
        return dp[i][last] = max(pick, notPick);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size(), mx = 0;
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) mx = max(mx, ages[i]), v.push_back({scores[i], ages[i]});
        sort(v.begin(), v.end());

        vector<vector<int>> dp(n, vector<int>(mx + 1, -1));
        return dfs(0, 0, n, v, dp);
    }
};
