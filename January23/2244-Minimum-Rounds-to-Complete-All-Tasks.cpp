class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for(int i : tasks) m[i]++;

        int ans = 0;
        for(auto i : m) {
            if(i.second == 1) return -1;
            else ans += ceil((double) i.second / 3);
        }
        return ans;

    }
};