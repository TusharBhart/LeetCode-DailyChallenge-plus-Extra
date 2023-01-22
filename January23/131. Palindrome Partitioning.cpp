class Solution {
    bool isPal(string &s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    void dfs(int i, string &s, vector<string> &v, vector<vector<string>> &ans, int n) {
        if(i == n) {
            ans.push_back(v);
            return;
        }
        for(int j=i; j<n; j++) {
            string str = s.substr(i, j - i + 1);
            if(isPal(str)) {
                v.push_back(str);
                dfs(j + 1, s, v, ans, n);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ans;

        dfs(0, s, v, ans, s.size());
        return ans;
    }
};