class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), start = 0, end = n - 1;
        while (start < end) {
            if (arr[start++] == 0) --end;
        };
        for (int i = n - 1; i >= 0; --i, --end) {
            arr[i] = arr[end];
            if (start != end && arr[end] == 0) {
                arr[--i] = arr[end];    
            };
        };
    };
};