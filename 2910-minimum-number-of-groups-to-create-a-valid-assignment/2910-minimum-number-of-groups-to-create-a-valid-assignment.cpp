class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        int n = nums.size(), minSize = INT_MAX, size = 1, count = 0;
        sort(begin(nums), end(nums));
        multiset<int> ms;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                size++;
            } else {
                ms.insert(size);
                size = 1;
            };
        };
        ms.insert(size);
        minSize = *ms.begin();
        
        for (int mid = minSize; mid >= 1; --mid) {
            int midPlusOne = mid + 1, ans = 0;
            for (auto &size : ms) {
                int curr = 0;
                for (int i = 0; !curr && mid * i <= size; ++i) {
                    for (int j = 0; !curr && midPlusOne * j <= size; ++j) {
                        if (mid * i + midPlusOne * j == size) {
                            curr = i + j;
                            ++count;
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
                cout << count << " " << size << "\n";
                return ans;
            };
        };
        return -1;
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