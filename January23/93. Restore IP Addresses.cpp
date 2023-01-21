// Recursive
class Solution {
    void dfs(int i, int cnt, string &s, string t, vector<string> & ans) {
        if(i == s.size() && cnt == 4) {
            t.pop_back();
            ans.push_back(t);
            return;
        }
        if(cnt > 4) return;
        for(int j=i; j<min(i + 3, (int)s.size()); j++) {
            if(stoi(s.substr(i, j - i + 1)) <= 255 && (i == j || s[i] != '0')) {
                dfs(j + 1, cnt + 1, s, t + s.substr(i, j - i + 1) + ".", ans);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.size() > 12) return ans;

        dfs(0, 0, s, "", ans);
        return ans;
    }
};

// Iterative
class Solution {
    bool good(string s) {
        string str;
        for(char c : s) {
            if(c == '.') {
                if(!str.size() || str.size() > 3 || stoi(str) > 255 || str[0] == '0' && str.size() > 1) return false;
                str = "";
            }
            else str += c;
        }
        if(!str.size() || str.size() > 3 || stoi(str) > 255 || str[0] == '0' && str.size() > 1) return false;
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    string ip = s.substr(0, i + 1) + "." + s.substr(i + 1, j - i) + "." + 
                                s.substr(j + 1, k - j) + "." + s.substr(k + 1);
                    if(good(ip)) ans.push_back(ip);
                }
            }
        }
        return ans;
    }
};