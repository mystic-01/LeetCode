class SummaryRanges {
private:
    set<int> s;
public:
    SummaryRanges() {

    };
    
    void addNum(int value) {
        s.insert(value);
    };
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto &it : s) {
            if (ans.size() && it == ans[ans.size() - 1][1] + 1) ans[ans.size() - 1][1] = it;
            else ans.push_back({it, it});
        };
        return ans;
    };
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */