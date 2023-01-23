class Solution {
    bool good(long long x, vector<int> &time, int tt) {
        long long cnt = 0;
        for(int i : time) {
            cnt += x / i;
            if(cnt >= 1e18) return true;
        }
        return cnt >= tt;
    }
public:
    long long minimumTime(vector<int>& time, int tt) {
        long long s = 1, e = 1e18, ans = 0;
        while(s <= e) {
            long long m = (s + e) / 2;
            if(good(m, time, tt)) e = m - 1, ans = m;
            else s = m + 1;
        }
        return ans;
    }
};