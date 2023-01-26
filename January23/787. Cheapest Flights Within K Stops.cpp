class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto e : flights) adj[e[0]].push_back({e[1], e[2]});

        queue<pair<pair<int, int>, int>> q;
        q.push({{src, 0}, k});
        vector<int> d(n, 1e9);
        d[src] = 0;

        while(q.size()) {
            int node = q.front().first.first, dis = q.front().first.second, p = q.front().second;
            q.pop();
            if(p < 0) continue;
            for(auto ad : adj[node]) {
                if(dis + ad.second < d[ad.first]) {
                    d[ad.first] = dis + ad.second;
                    q.push({{ad.first, d[ad.first]}, p - 1});
                }
            }
        }
        return d[dst] == 1e9 ? -1 : d[dst];
    }
};