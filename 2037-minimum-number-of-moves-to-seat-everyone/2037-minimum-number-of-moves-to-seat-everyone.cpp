class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        int n = students.size(), diff = 0;
        for (int i = 0; i < n; ++i) {
            diff += abs(seats[i] - students[i]);            
        };
        return diff;        
    };
};