class Solution {
public:
    // use two pointers
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());      
        int n = people.size(), i = 0, j = n - 1, boats = 0;
        
        while (i <= j) {
            if (i < j && people[j] + people[i] <= limit) i++;
            boats++, j--;
        };
        
        return boats;
    };
};