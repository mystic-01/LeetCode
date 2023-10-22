class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        int n = nums.size(), minSize = INT_MAX, best = 2147364847;
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[nums[i]]++;
        };

        for (auto &it : m) {
            minSize = min(minSize, (int)it.second);
        };
        
        for (int mid = 1; mid <= minSize; ++mid) {
            int midPlusOne = mid + 1, ans = 0;
            for (auto &it : m) {
                int size = it.second, curr = 0;
                for (int i = 0; !curr && mid * i <= size; ++i) {
                    for (int j = 0; !curr && midPlusOne * j <= size; ++j) {
                        if (mid * i + midPlusOne * j == size) {
                            curr = i + j;
                        }; 
                    };                
                };
                if (curr) {
                    ans += curr;
                } else {
                    ans = INT_MAX;
                    break;
                };
            };
            if (ans != INT_MAX) {
                best = min(best, ans);
            };
        };
        return best;
    };
};
/*
[3,2,3,2,3]
[10,10,10,3,1,1]
[1,1,3,3,1,1,2,2,3,1,3,2]
[1,1,1,1,1]

    5
    4
    3
        
        4 1
        
        
        */