class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int>::iterator it;
        for (int i = 0; i < numbers.size(); i++) {
            it = std::find (numbers.begin()+i+1, numbers.end(), target - numbers[i]);
            if (it - numbers.begin() < numbers.size()) {
                return numbers = {i+1, int(it - numbers.begin())+1};
            };
        };   
        return numbers;
    };
};