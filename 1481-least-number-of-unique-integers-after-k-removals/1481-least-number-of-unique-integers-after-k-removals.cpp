class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int &x : arr) {
            ++m[x];    
        };
        multiset<int> freqList;
        for (auto &it : m) {
            freqList.insert(it.second);
        };
        int elements = 0;
        for (auto &freq : freqList) {
            k -= freq;
            if (k < 0) {
                ++elements;            
            };
        };
        return elements;
    };
};