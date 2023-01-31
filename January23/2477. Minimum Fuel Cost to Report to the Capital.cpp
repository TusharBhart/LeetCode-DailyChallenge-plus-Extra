class Solution {
    int dfs(int node, int prnt, vector<int> adj[], int seats, long long &ans) {
        int cnt = 1;
        for(int ad : adj[node]) {
            if(ad != prnt) cnt += dfs(ad, node, adj, seats, ans);
        }
        if(node) ans += ceil((double)cnt / seats);
        return cnt;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans = 0, n = roads.size() + 1;
        vector<int> adj[n];
        for(auto e : roads) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);

        dfs(0, -1, adj, seats, ans);
        return ans;
    }
};