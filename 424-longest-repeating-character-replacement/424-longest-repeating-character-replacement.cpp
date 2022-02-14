// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.length(), left = 0, maxFreq = 0, charWithMaxFreq = 0, len = 0, best = 0;
//         unordered_map<int, int> m;
//         for (auto i = 0; i < n; i++) {
//             m[s[i]]++;
//             if (m[s[i]] > maxFreq) maxFreq = m[s[i]], charWithMaxFreq = 1;
//             else if (m[s[i]] == maxFreq) charWithMaxFreq++; 

//             len = i - left + 1;
//             while (len - maxFreq > k && left < n) {
//                 m[s[i]]--;
//                 maxFreq = max(maxFreq, m[s[i]]);
//                 len = i - left + 1;                                
//             };
//             best = max(best, i - left + 1);
//         };
//         return best;
//     };
// };

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), left = 0, maxCount = 0, charWithMaxFreq = 0, len = 0, best = 0;
        unordered_map<int, int> m;
        for (auto i = 0; i < n; i++) {
            maxCount = max(++m[s[i]], maxCount);
            len = i - left + 1;
            
            while (len - maxCount > k && left < n) {
                m[s[left++]]--;
                len = i - left + 1;                                
            };
            cout << i - left + 1 << " ";
            best = max(best, i - left + 1);
        };
        return best;
    };
};




















