class Solution {
    string build(int n, unordered_map<int, int> &m) {
        string s;
        int sum = 0;
        m[n]--;
        for(auto i : m){
            for(int j=0; j<i.second; j++) s += to_string(i.first), sum += i.first;
        }
        if(!s.size()) return "";
        if(!sum) return "0";

        sort(s.begin(), s.end(), greater<char>());
        if(sum % 3 == 0) return s;
        return "";
    }
    string solve(vector<int> v, unordered_map<int, int> &m) {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(v[i] == v[j]) {
                    if(m[v[i]] > 1) {
                        build(v[i], m);
                        return build(v[i], m);
                    }
                }
                else {
                    if(m[v[i]] && m[v[j]]) {
                        build(v[i], m);
                        return build(v[j], m);
                    }
                }
            }
        }
        return "";
    }
public:
    string largestMultipleOfThree(vector<int>& digits) {
        unordered_map<int, int> m;
        int sum = 0;
        for(int i : digits) m[i]++, sum += i;
        
        if(sum % 3  == 0) return build(-1, m);
        
        if(sum % 3 == 1) {
            if(m.count(1)) return build(1, m);
            if(m.count(4)) return build(4, m);
            if(m.count(7)) return build(7, m);
        }
        if(sum % 3 == 2) {
            if(m.count(2)) return build(2, m);
            if(m.count(5)) return build(5, m);
            if(m.count(8)) return build(8, m);
        }
        if(sum % 3 == 1) return solve({2, 5, 8}, m);
        return solve({1, 4, 7}, m);
    }
};