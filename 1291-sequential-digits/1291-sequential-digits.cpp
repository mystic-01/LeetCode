class Solution {
public:
    int incrementAllDigits(int num) {
        int incNum = 0, totalDigits = 0;
        bool isOverflowing = false;
        while (num) {
            int curr = num % 10;
            if (curr == 9) isOverflowing = true;
            incNum += ((curr + 1) * pow(10, totalDigits));
            ++totalDigits, num /= 10;
        };
        if (isOverflowing) {
            incNum = 0;
            for (int i = totalDigits, start = 1; i >= 0; --i, ++start) {
                incNum += (start * pow(10, i));
            };
        };
        return incNum;
    };
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        q.push(12);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr >= low && curr <= high) ans.push_back(curr);
            int next = incrementAllDigits(curr);
            if (next <= high) q.push(next);
        };
        return ans;
    };
};