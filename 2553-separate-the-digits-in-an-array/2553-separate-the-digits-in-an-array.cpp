class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int &x : nums) {
            vector<int> temp;
            while (x) {
                temp.push_back(x % 10);
                x /= 10;
            };
            reverse(temp.begin(), temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
        };
        return ans;
    };
};