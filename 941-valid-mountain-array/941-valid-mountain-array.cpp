class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size(), i = 0, j = n - 1, count = n - 1;
        if (n < 3 || arr[0] > arr[1]) return 0;
        while (i < j && count >= 0) {
            if (arr[i] < arr[i+1]) i++;
            if (arr[j] < arr[j-1]) j--;
            count--;
        };
        cout << i << " " << j;
        if (j - i > 1 || i == n - 1) return 0;
        if (i == j - 1 && arr[i] >= arr[j]) return 0;
        return 1;
    };
};