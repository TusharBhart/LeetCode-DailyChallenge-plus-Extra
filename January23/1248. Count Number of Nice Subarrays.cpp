class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), dis = 1, i = 0, cnt = 0, ans = 0;
        vector<int> d(n + 1, 1);

        for(int i=n-1; i>=0; i--) {
            nums[i] % 2 ? dis = 1 : dis++;
            d[i] = dis;
        }
       
        for(int j=0; j<n; j++) {
            if(nums[j] % 2) cnt++;

            while(i <= j && cnt == k) {
                ans += d[j + 1];
                if(nums[i] % 2) cnt--;
                i++;
            }
        }
        return ans;
    }
};