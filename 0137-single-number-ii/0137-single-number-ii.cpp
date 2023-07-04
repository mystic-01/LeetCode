// Do this using bit manip
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for (auto &x : nums) m[x]++;
        for (auto &it : m) if (it.second == 1) return it.first;
        return 0;
    };
};


/*

101
010


1000
0001
1110

0111




*/