class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size(), s = 0, j = 0, ans = -1, ps = 0;
        vector<int> v(n);
        for(int i=0; i<n; i++) {
            v[i] = gas[i] - cost[i];
            s += v[i];
        }
        if(s < 0) return -1;

        while(j % n != ans) {
            ps += v[j % n];
            if(ps < 0) ps = 0, ans = -1;
            else if(ans == -1) ans = j % n;
            j++;
        }
        return ans;
    }
};