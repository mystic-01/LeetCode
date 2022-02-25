class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), totalSum = 0, sum = 0, ans = 0;
        for (auto i = 0; i < n; i++) {
            totalSum += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) sum = 0, ans = i + 1;
        };
        return (totalSum < 0) ? -1 : ans;
    };
};