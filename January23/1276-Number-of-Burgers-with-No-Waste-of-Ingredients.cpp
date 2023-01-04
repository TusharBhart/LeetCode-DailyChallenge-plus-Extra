class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        if(!t && !c) return {0, 0};
        if(t < c * 2 || t % 2) return {};

        int j = 0, s = c;
        while(j < c) {
            if(4 * j + 2 * s == t) return {j, s};
            if(4 * j + 2 * s < t) j++, s--;
        }
        return {};
    }
};