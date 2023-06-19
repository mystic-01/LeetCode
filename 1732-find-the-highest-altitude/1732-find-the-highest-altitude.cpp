class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int hike = max(0, gain[0]);
        for (auto i = 1; i < gain.size(); i++) {
            gain[i] += gain[i - 1], hike = max(hike, gain[i]);            
        };
        return hike;
    };
};