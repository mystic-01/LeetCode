class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        map<int, string> m = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}, {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}};
        
        for (int i = 0; i < 4 && num; ++i, num /= 10) {
            int target = (num % 10) * pow(10, i);
            string curr = "";
            while (target) {
                auto it = m.lower_bound(target);
                if (target > 1000 || it->first > target) {
                    --it;    
                };
                curr += it->second, target -= it->first;            
            };
            ans = curr + ans;
        };
        return ans;
    };
};