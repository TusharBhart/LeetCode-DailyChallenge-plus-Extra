// Memoization
class Solution {
    int dfs(int i, int j, string &s, string &t, int n, int m, vector<vector<int>> &dp) {
        if(i == n) return m - j;
        if(j == m) return n - i;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = dfs(i + 1, j + 1, s, t, n, m, dp);
        return dp[i][j] = 1 + min(dfs(i + 1, j, s, t, n, m, dp), dfs(i, j + 1, s, t, n, m, dp));
    }
public:
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return dfs(0, 0, s, t, n, m, dp);
    }
};

// Tabulation
class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));

        for(int j=0; j<m; j++) dp[n][j] = m - j;
        for(int i=0; i<n; i++) dp[i][m] = n - i;

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(s[i] == t[j]) dp[i][j]= dp[i + 1][j + 1];
                else dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};