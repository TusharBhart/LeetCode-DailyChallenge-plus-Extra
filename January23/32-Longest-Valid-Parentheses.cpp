class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        s.push(-1);
        int ans = 0, n = str.size();

        for(int i=0; i<n; i++) {
            if(s.top() != -1 && str[s.top()] == '(' && str[i] == ')') s.pop(), ans = max(ans, i - s.top());
            else s.push(i);
        }
        return ans;
    }
};