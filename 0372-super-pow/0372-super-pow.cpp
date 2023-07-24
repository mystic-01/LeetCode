class Solution {
public:
    int superPow(int num, vector<int>& b) {
        long long ans = 1, a = num;
        int mod = 1337, i = 0, n = b.size();        
        while (i < n) {
            if (b.back() % 2) ans = (ans * a) % mod, b.back() -= 1;
            else {
                a = (a * a) % mod;
                int carry = 0;
                for (int j = 0; j < n; j++) {
                    if (carry) b[j] += (carry * 10);
                    carry = b[j] % 2;
                    b[j] /= 2;
                };
            };
            if (b[i] == 0) i++;
        };
        return ans;
    };
};