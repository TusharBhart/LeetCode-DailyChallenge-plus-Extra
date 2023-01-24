class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), l = 0;
        unordered_map<int, int> m;

        reverse(board.begin(), board.end());
        for(int i=0; i<n; i++) {
            if(i % 2) reverse(board[i].begin(), board[i].end());
            for(int j=0; j<n; j++) m[i * n + j + 1] = board[i][j];
        }

        queue<int> q;
        q.push(1);
        vector<int> vis(n * n + 1);
        vis[1] = 1;

        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                int curr = q.front(); q.pop();
                if(curr == n * n) return l;

                for(int i=curr+1; i<=min(curr + 6, n * n); i++) {
                    if(m[i] == -1 && !vis[i]) q.push(i), vis[i] = 1;
                    if(m[i] != -1 && !vis[m[i]]) q.push(m[i]), vis[m[i]] = 1;
                }
            }
            l++;
        }
        return -1;
    }
};