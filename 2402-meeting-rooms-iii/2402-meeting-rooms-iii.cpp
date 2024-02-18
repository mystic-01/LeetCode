// class Solution {
// public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         // heap {end, roomNo (0 - 100)};        
//         unordered_map<int, int> roomFreq;

//         int roomNo = -1, maxFreq = 0, maxFreqRoom = -1;
//         for (auto &vec : meetings) {
//             if (pq.size() < n) {
//                 roomNo = pq.size();
//                 pq.push({vec[1], roomNo});
//             } else {
//                 int newStart = pq.top().first, duration = vec[1] - vec[0];
//                 roomNo = pq.top().second; 
//                 pq.pop();
//                 pq.push({newStart + duration, roomNo});
//             };            
//             if (++roomFreq[roomNo] > maxFreq || (roomFreq[roomNo] == maxFreq && roomNo < maxFreqRoom)) {
//                 maxFreqRoom = roomNo, maxFreq = roomFreq[roomNo];    
//             };
//         };
//         return maxFreqRoom;
//     };
// };

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        unordered_map<int, int> roomFreq;
        sort(begin(meetings), end(meetings));
        
        long long endTimes[n], maxFreq = 0, maxFreqRoom = -1;
        fill(endTimes, endTimes + n, 0);
        for (auto &vec : meetings) {
            int roomNo = 0, newStart = vec[0], newEnd = vec[1], duration = vec[1] - vec[0];
            int roomWithsmallestEndTime = -1;
            long long smallestEndTime = LLONG_MAX; 
            while (roomNo < n) {
                if (newStart >= endTimes[roomNo]) {
                    endTimes[roomNo] = newEnd;
                    break;
                };    
                if (endTimes[roomNo] < smallestEndTime || (endTimes[roomNo] == smallestEndTime && roomNo < roomWithsmallestEndTime)) {
                    roomWithsmallestEndTime = roomNo, smallestEndTime = endTimes[roomNo];
                };
                ++roomNo;
            };

            if (roomNo == n) {
                roomNo = roomWithsmallestEndTime;
                endTimes[roomNo] = endTimes[roomNo] + long(duration);
            };
            if (++roomFreq[roomNo] > maxFreq || (roomFreq[roomNo] == maxFreq && roomNo < maxFreqRoom)) {
                maxFreqRoom = roomNo, maxFreq = roomFreq[roomNo];    
            };
        };
        return maxFreqRoom;
    };
};