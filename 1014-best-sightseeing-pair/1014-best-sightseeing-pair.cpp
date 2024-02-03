class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {
        int n = val.size(), bestFromRight = val.back(), maxScore = 0;
        for (int i = n - 2; i >= 0; --i) {
            maxScore = max(maxScore, --bestFromRight + val[i]);
            bestFromRight = max(val[i], bestFromRight);
        };
        return maxScore;
    };
};