class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int n = arr.size(), i = 0, j = n - 1;
        if (n < 3 || arr[0] > arr[1]) return 0;
        while (i < n - 2 && arr[i] < arr[i+1]) i++;
        while (j > 0 && arr[j] < arr[j-1]) j--;
        return i > 0 && i == j && j < n - 1;
    };
};