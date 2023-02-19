class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size(), maxSalary = salary[0], minSalary = salary[0], sum = 0;

        for (auto i = 0; i < n; i++) {
            if (salary[i] > maxSalary) maxSalary = salary[i];                
            if (salary[i] < minSalary) minSalary = salary[i];
            sum += salary[i];                
        };
        
        return (double)(sum - maxSalary - minSalary) / (double)(n - 2);
    };
};