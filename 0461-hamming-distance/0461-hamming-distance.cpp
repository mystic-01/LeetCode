class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while (x || y) {
            if ((x & 1) != (y & 1)) ans++;
            x /= 2, y /= 2;
        };
        return ans;
    };
};