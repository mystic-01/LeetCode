class Solution {
public:
    int brokenCalc(int start, int target) {
        int steps = 0;
        while (target > start)
            steps++, target = (target % 2 == 0) ? target / 2 : target + 1;
        return steps += (start - target);
//     int brokenCalc(int start, int target) {
//         queue<int> q;
//         set<int> visited;
//         q.push(start);
//         int steps = 0;
//         while (!q.empty()) {
//             int size = q.size();
//             for (auto i = 0; i < size; i++) {
//                 int curr = q.front(); 
//                 q.pop();
//                 visited.insert(curr);
//                 if (curr == target) return steps;
//                 if (curr - 1 && !visited.count(curr - 1)) q.push(curr - 1);
//                 if (curr * 2LL <= INT_MAX && !visited.count(curr * 2)) q.push(curr * 2);
//             };
//             steps++;
//         };
//         return steps;
    };
};