class SummaryRanges {
public:
    set<int> seen;
    SummaryRanges() {  
    }
    
    void addNum(int value) {
        seen.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int s = -1, e = -1;
        for(int i : seen) {
            if(s == -1) s = i, e = i;
            else if(e + 1 == i) e = i;
            else {
                ans.push_back({s, e});
                s = e = i;
            }
        }
        if(s != -1) ans.push_back({s, e});
        return ans;
    }
};