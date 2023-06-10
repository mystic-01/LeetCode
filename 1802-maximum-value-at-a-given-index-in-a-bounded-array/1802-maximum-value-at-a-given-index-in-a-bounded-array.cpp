class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int left = 0, right = maxSum, mid;
        while (left < right) {
            mid = (left + right + 1) / 2;
            if (test(n, index, mid) <= maxSum)
                left = mid;
            else
                right = mid - 1;
        }
        return left + 1;
    }

    long test(int n, int index, int a) {
        int b = max(a - index, 0);
        long res = long(a + b) * (a - b + 1) / 2;
        b = max(a - ((n - 1) - index), 0);
        res += long(a + b) * (a - b + 1) / 2;
        return res - a;
    }

};


/*

n = 5

idx = 2
mSum = 10

[1, 2, 3, 2, 1]

+1 = 0 + 1
+1 = 2 + 1
+1 = 4 + 1


i = 0

>>> (2 * i + 1)

idx = 1
mSum = 10

[2, 3, 2, 1, 0]

+1 = 0 + 1    i = 0
+1 = 2 + 1    i = 1
+1 = 4 + 1    i = 2


n = 3
idx = 2
mSum == 18

[1, 2, 3]

+1 = 0 + 1        i = 0
+1 = 2 + 1 - 1    i = 1
+1 = 4 + 1 - 1    i = 2
+1 = 4 + 1 - 1    i = 2


*/