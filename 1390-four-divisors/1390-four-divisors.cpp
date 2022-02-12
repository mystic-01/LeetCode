class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto x : nums) {
            int rootI = sqrt(x), curr = 0, i = 2, count = 0;
            if (pow(rootI, 2) != x) {
                
            while (i <= rootI) {
                if (x % i == 0) { 
                    curr += (i + (x / i));
                    count++;
                };
                if (count == 2) {
                    curr = 0;
                    break;
                };
                i++;
            };
            }
            if (curr) curr += (x + 1);
            sum += curr;
        };
        return sum;
    };
};