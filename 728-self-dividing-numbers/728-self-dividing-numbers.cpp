class Solution {
public:
    bool canDivideItself (int x) {
        int num = x;
        while (x) {
            int curr = (x % 10);
            if (curr && num % curr != 0) return 0;
            x /= 10;
            if (curr == 0 && x) return 0;
        };        
        return 1;
    };
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (canDivideItself(i)) ans.push_back(i);            
        };
        return ans;
    };
};