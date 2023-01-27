class Solution {
    bool dfs(int i, string &w, string t, int n, unordered_set<string> &s) {
        if(i == n) return true;

        for(int j=i; j<n; j++) {
            t += w[j];
            if(s.find(t) != s.end()) {
                return dfs(j + 1, w, "", n, s) || dfs(j + 1, w, t, n, s);
            }
        }
        return false;
    }
    bool good(string &w, unordered_set<string> &s) {
        s.erase(w);
        int n = w.size();
        bool ans =  dfs(0, w, "", n, s);
        s.insert(w);
        return ans;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> ans;

        for(string w : words) {
            if(good(w, s)) ans.push_back(w);
        }
        return ans;
    }
};