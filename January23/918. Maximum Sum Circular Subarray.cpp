class Solution {
    int kadane(vector<int> &nums) {
        int mx = -1e9, curr = 0;
        for(int i : nums) {
            curr += i;
            mx = max(mx, curr);
            if(curr < 0) curr = 0;
        }
        return mx;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), ans = 0, curr = 0, s = accumulate(nums.begin(), nums.end(), 0);
        vector<int> temp;
        for(int i : nums) temp.push_back(-i);

        int kp = kadane(nums), kn = kadane(temp);
        if(s + kn == 0) return kp;
        return max(kp, s + kn);
    }
};