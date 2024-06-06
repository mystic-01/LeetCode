class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(), groups = n / groupSize, prev = -1;
        map<int, int> m;

        if (n % groupSize) return false;
        
        for (auto &x : hand) m[x]++;
        
        for (auto &it : m) {
            if (it.second > 0) {
                for (auto i = 1, num = it.first; i < groupSize; i++) {
                    if (m[num + i] < m[num]) return false;  
                    m[num + i] -= m[num];
                };                
            };            
        };
        
        return true;
    };
};