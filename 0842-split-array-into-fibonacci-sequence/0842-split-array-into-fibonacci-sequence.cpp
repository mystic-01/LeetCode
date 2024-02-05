class Solution {
public:
    bool recurse(int idx, string &num, vector<int> &ans) {
        if (idx == num.size()) return ans.size() >= 3;

        for (int len = 1; len <= min(10, int(num.size() - idx)); ++len) {
            long currNum = stol(num.substr(idx, len)), ansSize = ans.size();
            if (currNum > 2147483647) break;
            if (num[idx] == '0' && currNum > 0) break;
            if (ansSize > 1 && ans[ansSize - 1] + (long)ans[ansSize - 2] != currNum) continue;
            
            ans.push_back(currNum);
            if (recurse(idx + len, num, ans)) return true;
            ans.pop_back();
        };
        return false;
    };

    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        recurse(0, num, ans);
        return ans;
    };
};

// 1 1 0 1 1 1 1
// 1 1 0 1 1 11
// ...
  // ...
// 11 0 1 1 1 1
