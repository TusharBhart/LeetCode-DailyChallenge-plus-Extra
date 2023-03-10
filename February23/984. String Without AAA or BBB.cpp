class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int f = 0;
        if(b > a) swap(a, b), f = 1;
        vector<vector<char>> v;

        while(a) {
            vector<char> r;
            r.push_back('a'), a--;
            if(!a) {
                v.push_back(r);
                break;
            }
            r.push_back('a'), a--;
            v.push_back(r);
        }
        while(b) {
            for(auto &r : v) {
                if(b) r.push_back('b'), b--;
            }
        }
        string ans;
        for(auto r : v) {
            for(char c : r) {
                ans += !f ? c : c == 'a' ? 'b' : 'a';
            }
        }
        return ans;
    }
};