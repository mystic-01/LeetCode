class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s, visited;
        for (auto i : wordList) s.insert(i);
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int res = 0;
        while (!q.empty()) {
            res++;
            int size = q.size();
            for (auto i = 0; i < size; i++) {
                string curr = q.front();
                if (curr == endWord) return res;
                q.pop();
                for (auto i = 0; i < curr.length(); i++) {
                    string temp = curr;
                    for (auto c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if (s.count(temp) && !visited.count(temp)) q.push(temp), visited.insert(temp);
                    };            
                };
            };
        };
        return 0;
    };
};