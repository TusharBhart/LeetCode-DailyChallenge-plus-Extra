class Solution {
public:
    int numberOfWays(string corridor) {
        int cnt = 0;
        for(char c : corridor) cnt += c == 'S';
        if(!cnt || cnt % 2) return 0;

        long long cntS = 0, cntP = 0, n = corridor.size(), ans = 1, mod = 1e9 + 7;
        for(int i=0; i<n; i++) {
            cntS += corridor[i] == 'S';
            if(cntS == 2) {
                while(i < n - 1 && corridor[i + 1] == 'P') cntP++, i++;
                if(i < n - 1) ans = (ans * ++cntP) % mod;
                cntP = cntS = 0;
            }
        }
        return ans;
    }
};