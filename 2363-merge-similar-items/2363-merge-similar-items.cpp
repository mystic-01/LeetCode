class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        sort(begin(items1), end(items1));
        sort(begin(items2), end(items2));
        
        int i = 0, j = 0, n1 = items1.size(), n2 = items2.size();
        while (i < n1 && j < n2) {
            if (items1[i][0] < items2[j][0]) ++i;    
            else if (items1[i][0] == items2[j][0]) items1[i][1] += items2[j][1], ++i, ++j;
            else items1.push_back(items2[j++]);    
        };
        while (j < n2) {
            items1.push_back(items2[j++]);    
        };        
        sort(begin(items1), end(items1));        
        return items1;
    };
};