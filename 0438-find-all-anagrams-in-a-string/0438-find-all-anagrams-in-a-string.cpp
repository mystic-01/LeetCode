class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<int, int> m;
        int dataLen = s.length(), testLen = p.length();

        for (auto i = 0; i < dataLen; i++) {
            m[s[i] - 'a']--;
            if (i < testLen) m[p[i] - 'a']++;

            if (i >= testLen - 1) {
                bool isAnagram = 1;
                for (auto &it : m) if (it.second != 0) isAnagram = 0;
                if (isAnagram) ans.push_back(i - testLen + 1);
                m[s[i - testLen + 1] - 'a']++;
            };
        };

        return ans;
    };
};