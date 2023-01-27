class Solution {
    int atmost(vector<int> &nums, int k) {
        int n = nums.size(), ans = 0, i = 0;
        unordered_map<int, int> m;

        for(int j=0; j<n; j++) {
            m[nums[j]]++;
            while(m.size() > k) {
                m[nums[i]]--;
                if(!m[nums[i]]) m.erase(nums[i]);
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};