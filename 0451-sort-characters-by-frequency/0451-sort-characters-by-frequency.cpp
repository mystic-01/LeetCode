class Solution {
public:
    string frequencySort(string s) {
        int n = s.size(), idx = 0;                   
        pair<char, int> freq[80];
        for (char &ch : s) {
            ++freq[ch - '0'].second, freq[ch - '0'].first = ch;
        };
        
        auto comp = [](const pair<char, int> p1, const pair<char, int> p2) {
            return p1.second == p2.second ? p1.first < p2.first :  p1.second > p2.second;
        };
        sort(begin(freq), end(freq), comp);
        
        for (char &ch : s) {
            while (!freq[idx].second) ++idx;
            ch = freq[idx].first, --freq[idx].second; 
        };
        return s;
    };
};