class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        // 1 Jan 1971 = Friday
        int daysSinceTimeBegan = day - 1;        
        for (auto i = 1; i < month; i++) {
            if (i == 4 || i == 6 || i == 9 || i == 11) daysSinceTimeBegan += 30;
            else if (i == 2) daysSinceTimeBegan += 28;
            else daysSinceTimeBegan += 31;
        };
        
        for (auto i = 1971; i < year; i++) {
            if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) daysSinceTimeBegan += 1;
            daysSinceTimeBegan += 365;
        };
        
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) && month > 2) daysSinceTimeBegan += 1;
        
        vector<string> v = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        
        return v[(daysSinceTimeBegan + 5) % 7];
    };
};