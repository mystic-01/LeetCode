class Solution {
public:
    bool isPalindrome(int num) {
        if (num < 0) return 0;
        vector<int> v;
        while (num) {
            v.push_back(num % 10);
            num /= 10;
        };
        int i = 0, j = v.size() - 1;
        while (i < j) if (v[i++] != v[j--]) return 0;
        return 1;
    };
};