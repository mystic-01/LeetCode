class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stuSize = students.size(), n = sandwiches.size();
        int ones = accumulate(students.begin(), students.end(), 0), zeros = n - ones;
        for (int i = 0; i < n; ++i) {
            if (sandwiches[i]) {
                if (ones) ones--;
                else return n - i;
            } else {
                if (zeros) zeros--;
                else return n - i;
            };
        };
        return 0;
    };
};