class Solution {
public:
    void recurse(int idx, int target, vector<int> &nums, set<vector<int>> &ans, vector<int> &ds) {
        if (target == 0) {
            ans.insert(ds);
            return;
        };
        if (idx == nums.size()) {
            return;
        };     
        if (target - nums[idx] >= 0) {
            target -= nums[idx];
            ds.push_back(nums[idx]);
            recurse(idx + 1, target, nums, ans, ds);
            ds.pop_back();
            target += nums[idx];
        };
        recurse(idx + 1, target, nums, ans, ds);
    };
    
    bool recurseAgain(auto it, int slotsLeft, unordered_map<int, int> &curr, unordered_map<int, int> &org, set<vector<int>> &ans) {
        if (it == ans.end()) {
            return slotsLeft == 0;            
        };
        
        bool take = false, notTake = false;
        bool wasted = false;
        for (const int &x : *it) {
            if (++curr[x] > org[x]) {
                wasted = true;
            };                        
        };        
        if (!wasted) {
            take = recurseAgain(it, slotsLeft - 1, curr, org, ans);                
        };
        for (const int &x : *it) {
            --curr[x];
        };
        notTake = recurseAgain(next(it, 1), slotsLeft, curr, org, ans);
        return take || notTake;
    };

    
    bool makesquare(vector<int>& nums) {
        int n = nums.size(), totSum = accumulate(begin(nums), end(nums), 0), target = totSum / 4;
        if (totSum % 4) {
            return false;            
        };
        unordered_map<int, int> org, curr;
        vector<int> ds;
        set<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            ++org[nums[i]];    
        };
        
        sort(begin(nums), end(nums));
        recurse(0, target, nums, ans, ds);
        auto it = begin(ans);
        return recurseAgain(it, 4, curr, org, ans);
    };
};

/*
 for (auto &vec : ans) {
            for (auto &s : vec) {
                cout << s << " ";
            };
            cout << "\n";
        };
        cout << "\n";
        cout << "\n";

[13,11,1,8,6,7,8,8,6,7,8,9,8]


[14,2,7,13,6,14,10,13,9,8,18,10,12,3,14]
[14,11,19,17,7,3,14,9,16,20,15,17,14,18,6]
[5969561,8742425,2513572,3352059,9084275,2194427,1017540,2324577,6810719,8936380,7868365,2755770,9954463,9912280,4713511]
[1,2,3,4,5,6,7,8,9,10,5,4,3,2,1]
[1,1,2,2,2]
[3,3,3,3,4]

*/