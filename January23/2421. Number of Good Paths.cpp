class Solution {
    int findPrnt(int node, vector<int> &prnt) {
        if(prnt[node] == node) return node;
        return prnt[node] = findPrnt(prnt[node], prnt);
    }
    void unionn(int u, int v, vector<int> &prnt, vector<int> &rank) {
        int ulp_u = findPrnt(u, prnt), ulp_v = findPrnt(v, prnt);

        if(rank[ulp_u] < rank[ulp_v]) prnt[ulp_u] = ulp_v;
        else if(rank[ulp_u] > rank[ulp_v]) prnt[ulp_v] = ulp_u;
        else prnt[ulp_v] = ulp_u, rank[ulp_u]++;
    }
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int ans = 0, n = vals.size();
        vector<int> adj[n];
        for(auto e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);

        vector<int> prnt(n), rank(n), seen(n);
        for(int i=0; i<n; i++) prnt[i] = i;

        map<int, vector<int>> m;
        for(int i=0; i<n; i++) m[vals[i]].push_back(i);

        for(auto i : m) {
            for(int node : i.second) {
                seen[node] = 1;
                for(int ad : adj[node]) {
                    if(seen[ad]) unionn(node, ad, prnt, rank);
                }
            }
            unordered_map<int, int> cnt;
            for(int node : i.second) cnt[findPrnt(node, prnt)]++;

            for(auto i : cnt) ans += i.second * (i.second - 1) / 2;
        }
        return ans + n;
    }
};