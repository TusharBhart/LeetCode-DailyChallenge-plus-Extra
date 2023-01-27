class Solution {
    void dfs(int i, string &s, string t, string &sen, int n, unordered_set<string> &st, vector<string> &ans) {
        if(i == n) {
            sen.pop_back();
            ans.push_back(sen);
            return;
        }
        for(int j=i; j<n; j++) {
            t += s[j];
            if(st.find(t) != st.end()) {
                string temp = sen;
                sen += t + " ";
                dfs(j + 1, s, "", sen, n, st, ans);
                sen = temp;
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<string> ans;

        string sen;
        dfs(0, s, "", sen, s.size(), st, ans);
        return ans;
    }
};