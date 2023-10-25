class Solution {
public:
    char recurse(long num, char curr, int &k, int div) {
        if (num == k) return curr;
        
        long alreadyProduced = (num - 1) * 2;
        
        if (k / (double)pow(2, div) <= alreadyProduced + 1 && k != alreadyProduced + 2) {
            return recurse(alreadyProduced + 1, curr == '0' ? '0' : '1', k, div - 1);
        } else {
            return recurse(alreadyProduced + 2, curr == '0' ? '1' : '0', k, div - 1);
        };
    };    
    
    int kthGrammar(int n, int k) {
        return recurse(1, '0', k, floor(log2(k))) - '0';
    };
};

/*
    elements = 2 ^(n - 1)        
    n = 4, k = 7
    
    0
    01
    0110
    01101001
    0110100110010110
    01101001100101101001011001101001


    011010011001011010
*/