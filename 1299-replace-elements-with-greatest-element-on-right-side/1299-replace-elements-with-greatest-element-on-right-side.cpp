class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatestElementOnRight = -1;
        for (int i = arr.size() - 1; i >= 0; --i) {
            swap(greatestElementOnRight, arr[i]);
            greatestElementOnRight = max(greatestElementOnRight, arr[i]);
        };
        return arr;
    };
};