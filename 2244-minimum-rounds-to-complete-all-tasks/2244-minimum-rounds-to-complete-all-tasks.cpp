class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int &x : tasks) {
            ++m[x];            
        };
        for (auto &[first, second] : m) {
            if (second == 1) return -1;
            ans += ((second / 3) + bool(second % 3));
        };
        return ans;
    };
};