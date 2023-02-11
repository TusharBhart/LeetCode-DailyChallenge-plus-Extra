class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> adj[n];
        for(auto e : redEdges) adj[e[0]].push_back({e[1], 0});
        for(auto e : blueEdges) adj[e[0]].push_back({e[1], 1});

        vector<vector<int>> d(n, vector<int>(2, 1e9));
        d[0][0] = 0;
        d[0][1] = 0;

        queue<vector<int>> q;
        q.push({0, 0, 0});
        q.push({0, 1, 0});

        while(q.size()) {
            int node = q.front()[0], color = q.front()[1], dis = q.front()[2];
            q.pop();

            for(auto ad : adj[node]) {
                if(color != ad.second && d[ad.first][ad.second] > dis + 1) {
                    d[ad.first][ad.second] = dis + 1;
                    q.push({ad.first, ad.second, d[ad.first][ad.second]});
                }
            }
        }
        vector<int> ans;
        for(auto p : d) {
            int mn = min(p[0], p[1]);
            ans.push_back(mn == 1e9 ? -1 : mn);
        }
        return ans;
    }
};