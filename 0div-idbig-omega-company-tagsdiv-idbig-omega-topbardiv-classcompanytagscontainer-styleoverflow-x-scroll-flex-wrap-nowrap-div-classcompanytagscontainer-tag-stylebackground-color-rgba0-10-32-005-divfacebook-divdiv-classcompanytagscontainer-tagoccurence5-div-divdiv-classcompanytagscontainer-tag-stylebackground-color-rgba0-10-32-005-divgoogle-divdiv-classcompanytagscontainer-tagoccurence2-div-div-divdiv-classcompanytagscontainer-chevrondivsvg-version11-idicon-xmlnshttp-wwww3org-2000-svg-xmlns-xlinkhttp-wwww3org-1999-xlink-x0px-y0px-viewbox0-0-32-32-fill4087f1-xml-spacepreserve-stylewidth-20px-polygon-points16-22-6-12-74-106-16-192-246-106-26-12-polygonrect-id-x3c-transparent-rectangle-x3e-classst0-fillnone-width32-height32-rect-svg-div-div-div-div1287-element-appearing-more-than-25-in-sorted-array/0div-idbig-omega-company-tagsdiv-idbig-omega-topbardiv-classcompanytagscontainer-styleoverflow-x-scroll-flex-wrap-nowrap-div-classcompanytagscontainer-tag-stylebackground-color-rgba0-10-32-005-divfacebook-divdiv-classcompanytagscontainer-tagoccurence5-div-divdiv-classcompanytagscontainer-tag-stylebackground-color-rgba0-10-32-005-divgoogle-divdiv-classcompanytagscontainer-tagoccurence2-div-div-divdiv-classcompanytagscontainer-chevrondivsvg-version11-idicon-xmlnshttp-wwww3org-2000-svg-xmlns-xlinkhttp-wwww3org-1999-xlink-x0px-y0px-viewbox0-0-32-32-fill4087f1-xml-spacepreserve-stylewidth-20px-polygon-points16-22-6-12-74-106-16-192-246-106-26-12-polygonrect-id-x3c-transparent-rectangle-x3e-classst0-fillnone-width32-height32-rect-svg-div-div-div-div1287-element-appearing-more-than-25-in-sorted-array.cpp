class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), curr = 0, freq = n / 4;
        for (int i = 0; i < arr.size(); ++i) {
            if (i == 0 || arr[i] == arr[i - 1]) ++curr;
            else curr = 1;
            
            if (curr > freq) return arr[i];
        };
        return -1;
    };
};