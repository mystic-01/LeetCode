class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);     
        
        int i = 0, j = 0, r = ransomNote.size(), m = magazine.size();
        if (r > m) return false;

        vector<int> v(26);
        
        while (i < m) {
            if (i < r) v[ransomNote[i] - 'a']--;
            v[magazine[i++] - 'a']++;
        }; 
        for (auto i : v) {
            if (i < 0) return false;
        };
        
        return true;
    };
};