class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        bool visited[1001] = {false};
        int n = nums.size(), steps = 0;
        
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                if (curr == goal) return steps;
                else if (curr < 0 || curr > 1000 || visited[curr]) continue;
                for (int j = 0; j < n; j++) {
                    for (int child : {curr + nums[j], curr - nums[j], curr ^ nums[j]}) {
                        q.push(child);
                    };
                };
                visited[curr] = true;
            };
            steps++;
        };
        return -1;
    };
};