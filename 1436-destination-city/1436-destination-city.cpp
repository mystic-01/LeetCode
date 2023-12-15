class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> start;
        for (auto &vec : paths) {
            start.insert(vec[0]);
        };
        for (auto &vec : paths) {
            if (start.count(vec[1]) == 0) return vec[1];
        };
        return "";
    };
};