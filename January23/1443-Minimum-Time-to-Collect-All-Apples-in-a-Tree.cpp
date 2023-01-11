class Solution {
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<bool> &ha, int &ans) {
        vis[node] = 1;
        bool r = false;
        for(int ad : adj[node]) {
            if(!vis[ad]) {
                r |= dfs(ad, adj, vis, ha,ans);
            }
        }
        if(ha[node]) r = true;
        if(r) ans += 2;
        return r;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int ans = 0;
        vector<int> adj[n];
        for(auto e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        vector<int> vis(n);

        dfs(0, adj, vis, hasApple, ans);
        return ans ? ans - 2 : 0;
    }
};