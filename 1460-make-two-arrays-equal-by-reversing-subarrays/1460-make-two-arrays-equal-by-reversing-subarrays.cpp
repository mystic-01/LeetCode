class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int v[1001] = {0}, n = arr.size();
        for (auto i = 0; i < n; i++) v[target[i]]++, v[arr[i]]--;
        for (auto j = 0; j < 1001; j++) if (v[j]) return false;
        return true;
    };
};