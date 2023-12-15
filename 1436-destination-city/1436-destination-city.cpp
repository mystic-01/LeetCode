class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> start;
        for (auto &vec : paths) {
            start.insert(vec[0]);
        };
        for (auto &vec : paths) {
            if (start.find(vec[1]) != start.end()) start.erase(vec[1]);
            else return vec[1];
        };
        return "";
    };
};