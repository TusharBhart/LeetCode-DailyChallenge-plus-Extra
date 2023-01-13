class Solution {
    pair<int, char> dfs(int node, vector<int> adj[], string &str, int &ans) {
        priority_queue<pair<int, int>> pq;
        for(int ad : adj[node]) {
            auto p = dfs(ad, adj, str, ans);
            if(p.second != str[node]) pq.push({p.first, p.second});
        }
        int mx = 0, d = 0;
        for(int i=0; i<2 && pq.size(); i++) {
            mx = max(mx, pq.top().first);
            d += pq.top().first, pq.pop();
        }
        ans = max(ans, d + 1);
        return {mx + 1, str[node]};
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.size(), ans = 0;
        vector<int> adj[n];
        for(int i=1; i<n; i++) adj[parent[i]].push_back(i);

        dfs(0, adj, s, ans);
        return ans;
    }
};