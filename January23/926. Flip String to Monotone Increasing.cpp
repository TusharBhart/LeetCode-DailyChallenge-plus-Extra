class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size(), ans = n, cnt0 = 0, cnt1 = 0;
        vector<int> l2r(n + 1), r2l(n + 1);

        for(int i=0; i<n; i++) {
            cnt1 += s[i] == '1';
            l2r[i + 1] = cnt1;
        }
        for(int i=n-1; i>=0; i--) {
            cnt0 += s[i] == '0';
            r2l[i] = cnt0;
        }
        
        for(int i=0; i<=n; i++) ans = min(ans, l2r[i] + r2l[i]);
        return ans;
    }
};