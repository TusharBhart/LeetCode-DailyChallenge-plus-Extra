class Solution {
public:
    int maxPerformance(int n, vector<int>& spd, vector<int>& eff, int k) {
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) v.push_back({eff[i], spd[i]});
        sort(v.begin(), v.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long s = 0, mod = 1e9 + 7, ans = 0;

        for(int i=n-1; i>=0; i--) {
            s += v[i].second;
            pq.push(v[i].second);

            if(pq.size() > k) {
                s -= pq.top();
                pq.pop();
            }
            ans = max(ans, v[i].first * s);
        }
        return ans % mod;
    }
};