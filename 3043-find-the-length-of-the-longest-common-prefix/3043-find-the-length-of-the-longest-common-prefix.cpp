class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size(), maxNum = 0;
        unordered_set<int> s;
        for (int i = 0; i < n1; ++i) {
            int temp = arr1[i];
            while (temp) {
                s.insert(temp);
                temp /= 10;
            };
        };
        
        for (int i = 0; i < n2; ++i) {
            int temp = arr2[i];
            while (temp) {
                if (s.count(temp)) {
                    maxNum = max(maxNum, temp);                
                };
                temp /= 10;
            };
        };
        
        int maxLen = 0;
        while (maxNum) {
            maxNum /= 10;
            ++maxLen;    
        };
        
        return maxLen;
    };
};