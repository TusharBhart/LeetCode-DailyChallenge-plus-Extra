class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size(),  carry = 0;
        if(n < m) swap(a, b), swap(n, m);
        for(int _=0; _<n-m; _++) b.insert(b.begin(), '0');
        string ans;
        
        for(int i=n-1; i>=0; i--) {
            int cnt = a[i] - '0' + b[i] - '0' + carry;
          
            if(!cnt) ans += '0', carry = 0;
            if(cnt == 1) ans += '1', carry = 0;
            if(cnt == 2) ans += '0', carry = 1;
            if(cnt == 3) ans += '1', carry = 1;
        }

        if(carry) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};