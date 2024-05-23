
class Solution {
private:
    int beautifulSubsets(vector<pair<int, int>>& s, int n, int k, int i) {
        if (i == n) {
            return 1;
        }
        int skip = beautifulSubsets(s, n, k, i + 1); // 1 * f(i + 1)
        int take = (1 << s[i].second) - 1; // take s[i]
        if (i + 1 < n && s[i + 1].first - s[i].first == k) { // next number is s[i] + k
            take *= beautifulSubsets(s, n, k, i + 2);
        } else {
            take *= beautifulSubsets(s, n, k, i + 1);
        }
        return skip + take;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int result = 1;
        map<int,     map<int,  int>> freq;
        // {remainder : {num : frequency}}
        // map is sorted based on num to get subset of form [x, x + k, x + 2k, ...]
        for (int& x: nums) { // splitting subsets based on remainder and calculating frequency
            freq[x % k][x]++;
        }
        for (auto& fr: freq) { // loop for s1, s2, ...
            vector<pair<int, int>> s(fr.second.begin(), fr.second.end());
            result *= beautifulSubsets(s, s.size(), k, 0); // f(s1) * f(s2) ...
        }
        return result - 1; // -1 for empty subset
    }
};