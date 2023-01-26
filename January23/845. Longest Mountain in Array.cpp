class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), cnt = 0, ans = 0;
        vector<int> l2r(n), r2l(n);

        for(int i=1; i<n; i++) {
            if(arr[i - 1] < arr[i]) {
                cnt++;
                l2r[i] = cnt + 1;
            }
            else cnt = 0;
        }
        cnt = 0;
        for(int i=n-2; i>=0; i--) {
            if(arr[i] > arr[i + 1]) {
                cnt++;
                r2l[i] = cnt + 1;
            }
            else cnt = 0;
        }

        for(int i=0; i<n; i++) {
            if(l2r[i] && r2l[i]) ans = max(ans, l2r[i] + r2l[i] - 1);
        }
        return ans;
    }
};