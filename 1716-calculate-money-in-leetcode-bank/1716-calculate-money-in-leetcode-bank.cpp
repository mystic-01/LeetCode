static int totDays = 7;
class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / totDays, sumOf1To7 = (totDays * (totDays + 1)) / 2 /* (7 * 8 / 2) = 28 */;
        int days = n % totDays, sumOf1ToDays = (days * (days + 1)) / 2;

        return (sumOf1To7 * weeks) + (totDays * ((weeks - 1) * weeks / 2)) + sumOf1ToDays + (days * weeks);
    };
};

        /*
        1 -> 1-7 * 1 + 7 * 0
        2 -> 1-7 * 2 + 7 * 1
        3 -> 1-7 * 3 + 7 * 1 + 2
        4 -> 1-7 * 3 + 7 * 1 + 2 + 3
        */
