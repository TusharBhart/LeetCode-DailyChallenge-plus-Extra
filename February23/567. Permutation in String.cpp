class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), k = s1.size(), i = 0;
        unordered_map<char, int> m, t;
        for(char c : s1) m[c]++;

        for(int j=0; j<n; j++) {
            t[s2[j]]++;
            if(j - i + 1 == k) {
                if(m == t) return true;
                t[s2[i]]--;
                if(!t[s2[i]]) t.erase(s2[i]);
                i++;
            }
        }
        return false;
    }
};