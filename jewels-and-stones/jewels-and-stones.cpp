class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        auto gems = 0;
        for (auto j = 0; j < stones.length(); j++) {
            auto it = find(jewels.begin(), jewels.end(), stones[j]);
            if (it != jewels.end()) gems++;
        };
        return gems;
    };
};