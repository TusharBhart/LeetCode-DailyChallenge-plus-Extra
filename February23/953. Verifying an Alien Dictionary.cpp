class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        unordered_map<char, int> m;
        for(int i=0; i<26; i++) m[order[i]] = i;

        for(int i=0; i<n-1; i++) {
            string s = words[i], t = words[i + 1];
            int j = 0;
            while(j < min(s.size(), t.size()) && s[j] == t[j]) j++;
            if(j == min(s.size(), t.size()) && s.size() > t.size()) return false; 
            if(m[s[j]] > m[t[j]]) return false;
        }
        return true;
    }
};