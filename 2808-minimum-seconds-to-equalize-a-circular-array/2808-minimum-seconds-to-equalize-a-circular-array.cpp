class Solution {
public:
    
    int minimumSeconds(vector<int>& nums) {
        map<int, pair<int, int>> m;
        int n = nums.size(), minMovesReq = INT_MAX;
        
        for (int i = 0; i < 2 * n; i++) {
            if (m.find(nums[i % n]) == m.end()) m[nums[i % n]] = {i, i};
            else m[nums[i % n]] = {max(m[nums[i % n]].first, i - m[nums[i % n]].second), i};
        };
        
        for (auto &it : m) {
            minMovesReq = min(minMovesReq, it.second.first);
        };
        
        minMovesReq -= 1;
        return minMovesReq / 2 + minMovesReq % 2;
    };
};


/*
[8,8,9,10,9]
[8,13,3,3]
[1,2,1,2]
[2,1,3,3,2]
[5,5,5,5]
[11,4,10]

3 2 4
2

3 3 2
2

1 1
1

3 4 3
3

0

2 2 2
2
*/