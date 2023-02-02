class Solution {
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &idx) {
        vis[node] = 1;
        idx.push_back(node);

        for(int ad : adj[node]) {
            if(!vis[ad]) dfs(ad, adj, vis, idx);
        }
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size(), ans = 0;
        vector<int> vis(n);
        vector<int> adj[n];
        for(auto e : allowedSwaps) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);

        for(int i=0; i<n; i++) {
            if(vis[i]) continue;
            vector<int> idx;
            unordered_map<int, int> m;
            int cnt = 0;
            dfs(i, adj, vis, idx);

            for(int j : idx) m[source[j]]++, m[target[j]]--;
            for(auto j : m) cnt += abs(j.second);
            ans += cnt / 2;
        }
        return ans;
    }
};