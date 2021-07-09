class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int> v(boxes.length(), 0);
        for (auto i = 0; i < boxes.length(); i++) {
          if (boxes[i] == '1') {
            for (auto j = 0; j < v.size(); j++) {
                v[j] += abs(i - j);
            };   
          };
        };
        return v;
    };
};