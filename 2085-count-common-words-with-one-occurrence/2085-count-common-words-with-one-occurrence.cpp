class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int answer = 0;
        map<string, int> m;
        for (auto i : words1) m[i]++;
        for (auto i : words2) if (m[i] == 1) m[i]--; else m[i] = INT_MAX;
        for (auto i : m) answer += i.second == 0 ? 1 : 0;
        return answer;
    };
};