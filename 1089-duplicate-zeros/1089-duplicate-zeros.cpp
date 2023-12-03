class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> memory;
        for (int &x : arr) {
            if (x == 0) {
                memory.push(0);
            };
            if (memory.size()) {
                memory.push(x);
                x = memory.front();
                memory.pop();
            };
        };
    };
};