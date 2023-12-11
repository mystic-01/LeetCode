class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), freq = n / 4;
        unordered_map<int, int> m;
        for (int &x : arr) {
            if (++m[x] > freq) return x;
        };
        return -1;
    };
};