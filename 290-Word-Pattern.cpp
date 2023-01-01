class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string w;
        for(char c : s) {
            if(c == ' ') words.push_back(w), w = "";
            else w += c;
        }
        words.push_back(w);
    
        if(words.size() != pattern.size()) return false;
       
        unordered_map<char, int> m;
        unordered_map<string, int> c;
        for(int i=0; i<pattern.size(); i++) {
            if(m[pattern[i]] != c[words[i]]) return false;
            m[pattern[i]] = i + 1;
            c[words[i]] = i + 1;
        }
        return true;
    }
};