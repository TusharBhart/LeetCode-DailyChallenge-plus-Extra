class Solution {
public:
    bool canChange(string s, string t) {
        int i = 0, j = 0, n = s.size(), m = t.size();
        while(i < n || j < m) {
            while(s[i] == '_') i++;
            while(t[j] == '_') j++;

            if(s[i] != t[j]) return false;
            if(s[i] == 'R' && i > j) return false;
            if(s[i] == 'L' && i < j) return false;
            i++, j++;
        }
        return true;
    }
};