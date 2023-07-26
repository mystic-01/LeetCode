/*
Approach 1: 

By comparing bits of curr & target
TC - O(n * logn)
SC - O(1)

*/
    
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size(), curr = pref[0];
        
        for (int i = 1; i < n; i++) {
            int x = 0;
            // We know, curr ^ x = pref[i] => x = curr ^ pref[i];
            x = curr ^ pref[i];
            curr = pref[i], pref[i] = x;
        };
        return pref;
    };
};

/*

Approach 1: 

By comparing bits of curr & target
TC - O(n * logn)
SC - O(1)

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size(), curr = pref[0];
        
        for (int i = 1; i < n; i++) {
            int target = pref[i], num = 0, bit = 0;
            while (curr || target) {
                if ((curr & 1) != (target & 1)) {
                    num = num | (1 << bit);
                };
                curr /= 2, target /= 2, bit++;
            };
            curr = pref[i], pref[i] = num;  
        };
        return pref;
    };
};
/*

1 ^ 0 -> 1
1 ^ 1 -> 0
0 ^ 0 -> 0
0 ^ 1 -> 1

5 ^ x = 2
    
    101
    // 111
    010
    // 010
    000    
    011
    0 0 -> 0
    1 0 -> 1
    001
*/