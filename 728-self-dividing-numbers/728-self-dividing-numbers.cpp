class Solution {
public:
    bool canDivideItself (int x) {
        int num = x, curr = 0;
        while (num) {
            curr = num % 10;
            num /= 10;

            if ((curr && x % curr != 0) || (!curr && num)) return 0;
        };        
        return 1;
    };
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) if (canDivideItself(i)) ans.push_back(i);            
        return ans;
    };
};