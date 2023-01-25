class Solution {
    void dfs(int node, int dis, vector<int> &adj, vector<int> &d) {
        d[node] = dis;
        if(adj[node] != -1 && d[adj[node]] == 1e9) dfs(adj[node], dis + 1, adj, d); 
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), ans = -1, mn = 1e9;
        vector<int> d1(n, 1e9), d2(n, 1e9);
        dfs(node1, 0, edges, d1);
        dfs(node2, 0, edges, d2);

        for(int i=0; i<n; i++) {
            if(max(d1[i], d2[i]) != 1e9 && max(d1[i], d2[i]) < mn) ans = i, mn = max(d1[i], d2[i]);
        }
        return ans;
    }
};