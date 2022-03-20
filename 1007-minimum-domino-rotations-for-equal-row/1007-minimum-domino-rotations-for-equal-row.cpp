class Solution {
public:
    // Fund the mistake!!!!!!
    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
        int n = top.size(), candidate1 = top[0], candidate2 = bottom[0], candidate3 = bottom[0], candidate4 =               top[0], change1 = 0, change2 = 0, change3 = 0, change4 = 0;
        for (auto i = 0; i < n; i++) {
            if (top[i] == candidate1);
            else if (bottom[i] == candidate1) change1++; 
            else candidate1 = -1, change1 = INT_MAX;
            
            if (top[i] == candidate3);
            else if (bottom[i] == candidate3) change3++; 
            else candidate3 = -1, change3 = INT_MAX;
            
            if (bottom[i] == candidate2);
            else if (top[i] == candidate2) change2++; 
            else candidate2 = -1, change2 = INT_MAX;
            
            if (bottom[i] == candidate4);
            else if (top[i] == candidate4) change4++; 
            else candidate4 = -1, change4 = INT_MAX;
        };
        int ans = min(min(change1, change2), min(change3, change4));
        return ans == INT_MAX ? -1 : ans;
    };
};