// Memoization
class Solution {
    int dfs(int i, int j, string &s, string &t, int n, int m, vector<vector<int>> &dp) {
        if(i == n) {
            int sum = 0;
            for(int k=j; k<m; k++) sum += t[k];
            return sum;
        }
        if(j == m) {
            int sum = 0;
            for(int k=i; k<n; k++) sum += s[k];
            return sum;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = dfs(i + 1, j + 1, s, t, n, m, dp);
        return dp[i][j] = min(s[i] + dfs(i + 1, j, s, t, n, m, dp), t[j] + dfs(i, j + 1, s, t, n, m, dp));
    }
public:
    int minimumDeleteSum(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return dfs(0, 0, s, t, n, m, dp);
    }
};

// Tabulation
class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for(int j=0; j<m; j++) {
            int sum = 0;
            for(int k=j; k<m; k++) sum += t[k];
            dp[n][j] = sum;
        }
        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int k=i; k<n; k++) sum += s[k];
            dp[i][m] = sum;
        }

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                if(s[i] == t[j]) dp[i][j] = dp[i + 1][j + 1];
                else dp[i][j] = min(s[i] + dp[i + 1][j], t[j] + dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};