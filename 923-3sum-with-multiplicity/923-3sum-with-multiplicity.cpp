class Solution {
public:
    long long combinatrics(int N, int r) {
        long long int res = 1, mod = 1e9 + 7;
        for (auto i = 1; i <= r; i++)
            res = res * (N - r + i) / i, res %= mod; 
        return res;
    };
    
    int threeSumMulti(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for (auto &it : nums) m[it]++;
        
        int n = nums.size(), i = 0, j, k, a, b, c;
        long long int count = 0, prod = 1;
        while (i < n - 2) {
            a = nums[i], j = i + 1, k = n - 1;
            while (j < k) {
                b = nums[j], c = nums[k];
                if (b + c == target - a) {
                    prod = 1;
                    unordered_map<int, int> triplet;
                    triplet[a]++, triplet[b]++, triplet[c]++;
                    for (auto &x : triplet) prod *= combinatrics(m[x.first], x.second);;
                    count += prod;
                    while (j < n && nums[j] == b) j++;
                    while (k >= 0 && nums[k] == c) k--;
                } else if (b + c < target - a) while (j < n && nums[j] == b) j++;
                else while (k >= 0 && nums[k] == c) k--;
            };
            while (i < n - 2 && nums[i] == a) i++;
        };
        return (int)count;
    };
};