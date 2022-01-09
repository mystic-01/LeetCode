/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int ans = guess(mid);
            if (ans == 0) return mid;
            else if (ans == -1) hi = mid;
            else lo = mid + 1;
        };
        return hi;
    };
};