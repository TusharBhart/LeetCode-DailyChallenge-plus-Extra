class Solution {
    vector<int> dfs(int node, int prnt, vector<int> adj[], string &lb, vector<int> &ans) {
        vector<int> v(26);

        for(int ad : adj[node]) {
            if(ad == prnt) continue;
            vector<int> t = dfs(ad, node, adj, lb, ans);
            for(int i=0; i<26; i++) v[i] += t[i];
        }
        ans[node] = ++v[lb[node] - 'a'];
        return v;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n];
        for(auto e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        vector<int> ans(n);

        dfs(0, -1, adj, labels, ans);
        return ans;
    }
};