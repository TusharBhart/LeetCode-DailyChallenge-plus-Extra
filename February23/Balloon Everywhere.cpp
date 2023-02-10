class Solution{
public:
    int maxInstance(string s){
        unordered_map<char, int> m;
        unordered_set<char> st = {'b', 'a', 'l', 'o', 'n'};
        
        for(char c : s) {
            if(st.find(c) != st.end()) m[c]++;
        }
        
        return min(m['b'], min(m['a'], min(m['n'], min(m['l'] / 2, m['o'] / 2))));
    }
};