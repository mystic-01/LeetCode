class Solution {
public:
    string customSortString(string order, string s) {
        int position[26] = {26};
        for (int i = 0; i < order.size(); ++i) {
            position[order[i] - 'a'] = i;    
        };
        auto comp = [&position](char &ch1, char &ch2) {
            return position[ch1 - 'a'] < position[ch2 - 'a'];
        };
        sort(begin(s), end(s), comp);
        return s;
    };
};