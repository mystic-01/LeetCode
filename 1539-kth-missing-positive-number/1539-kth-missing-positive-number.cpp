class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), prev = 0, missingCount = 0, start = -1;
        for (auto i = 0; i < n; i++) {
            missingCount += (arr[i] - prev - 1), prev = arr[i];
            if (missingCount >= k) {
                start = arr[i] - 1;
                while (missingCount != k) missingCount--, start--;
                return start;
            };
        };
        start = arr[n - 1];
        while (missingCount != k) start++, missingCount++;
        return start;
    };
};
