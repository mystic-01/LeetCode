class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        auto x = 0;
        for (auto i = 0; i < operations.size(); i++)
            x = (operations[i][1] == '+') ? x + 1 : x - 1;
        return x;
    };
};