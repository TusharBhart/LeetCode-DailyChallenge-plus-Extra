// Memoization
class Solution {
    int dfs(int i, vector<int> &dp) {
        if(!i) return 0;
        if(i == 1 || i == 2) return 1;
        if(dp[i] != -1) return dp[i];
        
        return dp[i] = dfs(i - 1, dp) + dfs(i - 2, dp) + dfs(i - 3, dp);
    }
public:
    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return dfs(n, dp);
    }
};

// Tabulation
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n + 1);
        if(n >= 1) dp[1] = 1;
        if(n >= 2) dp[2] = 1;
        for(int i=3; i<=n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};

// Space Optimization
class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        for(int i=3; i<=n; i++) {
            int d = c + b + a;
            a = b;
            b = c;
            c = d;
        }
        return !n ? 0 : c;
    }
};