class Solution {
public:
    // use two pointers
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());      
        int n = people.size(), i = 0, j = n - 1, currWeight = 0, boats = 0;
        while (i <= j) {
            int currWeight = people[j];
            if (i < j && currWeight + people[i] <= limit) currWeight += people[i++];
            boats++, j--;
        };
        return boats;
    };
};