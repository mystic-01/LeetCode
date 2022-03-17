class Solution {
public:
//     int scoreOfParentheses(string s) {
//         stack<int> st;
//         int left = 0, right = 0, total = 0;
//         for (auto &i : s) {
//             if (i == '(') left++;
//             else right++;
            
//             if (left == right) total += max(1, 2 * (left - 1)), left = right = 0;
//         };      
//         return total;
//     };
      int scoreOfParentheses(string S) {
        stack<int> stack;
        int cur = 0;
        for (char i : S)
            if (i == '(') {
                stack.push(cur);
                cur = 0;
            }
            else {
                cur += stack.top() + max(cur, 1);
                stack.pop();
            }
        return cur;
    }
};