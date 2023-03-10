class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = 0, n = nums.size(), s = 0, cnt = 0, target = 0;
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++) v.push_back({nums[i], cost[i]}), s += cost[i];
        sort(v.begin(), v.end());

        for(int i=0; i<n; i++) {
            cnt += v[i].second;
            if(cnt > s / 2) {target = v[i].first; break;}
        }

        for(int i=0; i<n; i++) ans += abs(nums[i] - target) * cost[i];
        return ans;
    }
};