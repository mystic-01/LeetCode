class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size(), ones = 0, zeros = 0;
        for (int &x : students) {
            ones += (x == 1);
            zeros += (x == 0);
        };
        for (int i = 0; i < n; ++i) {
            if (sandwiches[i] == 0) {
                if (!zeros) {
                    break;
                };    
                --zeros;
            } else {
                if (!ones) {
                    break;
                };
                --ones;
            };
        };
        return ones + zeros; 
    };
};