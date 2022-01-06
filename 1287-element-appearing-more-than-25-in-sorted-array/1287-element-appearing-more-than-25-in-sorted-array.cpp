class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), count = 1, num = arr[0];
        for (int i = 1; i < n; i++) {
            if (count > (n / 4)) return num;
            if (arr[i] != num) {
                count = 0;
                num = arr[i];
            };
            count++;
        };
        return num;
    };
};