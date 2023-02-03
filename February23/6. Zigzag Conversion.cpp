class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size(), i = 0, j = 0, k = 0;
        vector<vector<char>> v(numRows, vector<char>(n, '#'));

        while(k < n) {
            while(k < n && i < numRows) v[i++][j] = s[k++];
            i = max(0, i - 2);
            j++;
            for(int _=0; _<numRows-2 && k < n; _++) v[i--][j++] = s[k++];
        }

        string ans;
        for(auto r : v) {
            for(char c : r) {
                if(c != '#') ans += c;
            }
        }
        return ans;
    }
};