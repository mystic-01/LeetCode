class Solution {
public:
    int recurse(int idx, int mask, vector<string>& arr) {
        if (idx == arr.size()) return mask;
        
        bool canTakeNewMask = true;
        int newMask = mask;
        for (char &ch : arr[idx]) {
            int val = ch - 'a';
            if ((newMask >> val) & 1 == 1) canTakeNewMask = false;
            else newMask = newMask | (1 << val);
        };
        
        int take = canTakeNewMask ? recurse(idx + 1, newMask, arr) : 0;
        int notTake = recurse(idx + 1, mask, arr);
        return __builtin_popcount(take) > __builtin_popcount(notTake) ? take : notTake;
    };
    
    int maxLength(vector<string>& arr) {
        int mask = 0, ansVal = recurse(0, mask, arr), ansBits = 0;
        while (ansVal) {
            ansBits += (ansVal & 1), ansVal >>= 1;
        };
        return ansBits;
    };
};