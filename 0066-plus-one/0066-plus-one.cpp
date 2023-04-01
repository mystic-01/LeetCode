class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        reverse(digits.begin(), digits.end());
        
        for (auto &x : digits) x += carry, carry = x / 10, x = x % 10; 
        if(carry) digits.push_back(carry);
        
        reverse(digits.begin(), digits.end());
        return digits;
    };
};