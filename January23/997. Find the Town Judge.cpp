class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> t(n + 1);
        for(int i=0; i<trust.size(); i++) {
            t[trust[i][1]]++;
            t[trust[i][0]]--;
        }

        for(int i=1; i<=n; i++) {
            if(t[i] == n - 1) return i;
        }
        return -1;
    }
};