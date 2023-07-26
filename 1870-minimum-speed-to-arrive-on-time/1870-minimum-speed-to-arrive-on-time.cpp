class Solution {
public:
    int minSpeedOnTime(vector<int>& nums, double hour) {
        int n = nums.size(), lo = 1, hi = 1e7, ans = 0;        
        if (hour <= n - 1) return -1;
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            double time = 0;
            for (int i = 0; i < n; i++) {
                double currTime = nums[i] / (double)mid;
                // cout << i << " " << ceil(currTime) << "\n";
                if (i != n - 1) time += ceil(currTime);
                else time += currTime;
            };
            // cout << time << " " << ans << " " << lo << " " << hi << " " << "\n"; 
            if (time <= hour) ans = mid, hi = mid - 1;
            else lo = mid + 1;
        };
        return ans;
    };
};