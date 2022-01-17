class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int answer = 0, w1 = words1.size(), w2 = words2.size();
        unordered_map<string, pair<int, int>> m;
        for (auto i = 0; i < w1 || i < w2; i++) {
            if (i < w1) m[words1[i]].first++;     
            if (i < w2) m[words2[i]].second++;
        }; 
        for (auto i : m) answer += i.second.first == i.second.second && i.second.second == 1 ? 1 : 0;
        return answer;
    };
};