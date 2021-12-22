class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        map<char, vector<int>> m;
        for (auto j = 0; j < 27; j++) 
            m['a' + j] = vector<int>(words.size());
        
        for (auto i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].length(); j++) 
                m[words[i][j]][i]++;

        words = {};
        for(auto i = m.begin(); i != m.end(); ++i) {
            vector<int> v = (*i).second;
            auto check = v[0];
            for (auto j = 0; j < v.size(); j++) {
                check = min(check, v[j]);
            }
            
            for ( ; check > 0; check--) {
                string s(1, (*i).first);
                words.push_back(s);
            };
        }
        return words;
    };
};