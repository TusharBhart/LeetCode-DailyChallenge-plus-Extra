class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int s = 0, ans = 0;
        unordered_map<int, int> m;
        m[0] = 1;

        for(int i : nums) {
            s += i;
            int r = s % k;
            if(r < 0) r += k;
            if(m.find(r) != m.end()) ans += m[r];
            m[r]++;
        }
        return ans;
    }
};