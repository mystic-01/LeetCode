class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        unordered_map<int, int> roomFreq;
        sort(begin(meetings), end(meetings));
        
        int maxFreq = 0, maxFreqRoom = -1;
        long endTimes[n];
        fill(endTimes, endTimes + n, 0LL);
        for (auto &vec : meetings) {
            int roomNo = 0, newStart = vec[0], newEnd = vec[1], duration = vec[1] - vec[0];
            
            int roomWithsmallestEndTime = -1;
            long smallestEndTime = LLONG_MAX; 
            while (roomNo < n) {
                if (newStart >= endTimes[roomNo]) {
                    endTimes[roomNo] = newEnd;
                    break;
                };    
                if (endTimes[roomNo] < smallestEndTime) {
                    roomWithsmallestEndTime = roomNo, smallestEndTime = endTimes[roomNo];
                };
                ++roomNo;
            };

            if (roomNo == n) {
                roomNo = roomWithsmallestEndTime;
                endTimes[roomNo] += long(duration);
            };
            if (++roomFreq[roomNo] > maxFreq || (roomFreq[roomNo] == maxFreq && roomNo < maxFreqRoom)) {
                maxFreqRoom = roomNo, maxFreq = roomFreq[roomNo];    
            };
        };
        return maxFreqRoom;
    };
};