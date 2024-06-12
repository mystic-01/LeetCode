class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size(), idx = 0;
        map<int, int> m;
        
        for (auto &x : arr1) m[x]++;  
        
        for (auto i = 0; i < n2; i++) {
            while (m[arr2[i]]--) {
                arr1[idx++] = arr2[i];                
            };        
        };
        
      
        for (auto &it : m)  {
            while (it.second > 0 && it.second--) {
                arr1[idx++] = it.first;                             
            };
        };
        
        return arr1;
    };
};