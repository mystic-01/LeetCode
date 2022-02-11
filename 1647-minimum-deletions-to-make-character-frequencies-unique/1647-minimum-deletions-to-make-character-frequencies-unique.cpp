
/*
// Solution using 2 * O(26) space & O(n) + O (26 * 26) time.
class Solution {
public:
    int minDeletions(string s) {
        int v[26] = {0};
        unordered_map<int, int> m;
        int n = s.length(), count = 0;
        
        for (auto i : s) v[i - 'a']++;
        
        for (auto i = 0; i < 26; i++) {
            while(v[i] && m[v[i]]) v[i]--, count++;
            m[v[i]]++;
        };
        return count;
    };
};
*/

// Solution using O(26) space & O(n) + O (26) time.
class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);

        for (auto i : s) v[i - 'a']++;
        sort(v.begin(), v.end(), greater<int>());
        
        int count = 0, prev = v[0] + 1; 
        for (auto i = 0; i < 26; i++) {
            if (!v[i] || !prev) break;
            
            prev = min(v[i], prev - 1);
            count += prev;
        };
        return s.length() - count;
    };
};
















