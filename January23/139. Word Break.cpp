class Solution {
    bool dfs(int i, string &s, string t, unordered_set<string> &st, int n, vector<int> &dp) {
        if(i == n) return 1;
        if(dp[i] != -1) return dp[i];

        for(int j=i; j<n; j++) {
            t += s[j];
            if(st.find(t) != st.end()) {
                if(dfs(j + 1, s, "", st, n, dp) || dfs(j + 1, s, t, st, n, dp)) return dp[j] = 1;
            }
        }
        return dp[i] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(n, -1);
        return dfs(0, s, "", st, n, dp);
    }
};