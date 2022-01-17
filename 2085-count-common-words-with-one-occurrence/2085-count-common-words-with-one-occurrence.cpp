class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int answer = 0;
        map<string, pair<int, int>> m;
        for (auto i : words1) m[i].first++;
        for (auto i : words2) m[i].second++;
        for (auto i : m) answer += i.second.first == i.second.second && i.second.second == 1 ? 1 : 0;
        return answer;
    };
};